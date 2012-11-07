#include "Message.h"
#undef SendMessage
#include "assert.h"

MessageListener::MessageListener(void)
{
}

MessageListener::~MessageListener(void)
{
}

bool MessageListener::HandleMessage(Message *pMessage)
{
	return true;
};

// send a message (simply pass through to the MessageManager)
void MessageListener::Send(unsigned int idSender,MessageType msgType,int iValue,void *pData,unsigned int idReciever)
{
   MessageManager::GetInstance().Send(idSender,msgType,iValue,pData,idReciever);
}

MessageManager::MessageManager(void)
{
   mDelegates.reserve(500);
   bIsSending = false;
}

MessageManager::~MessageManager(void)
{
}


MessageDelegate* MessageManager::SubscribeMessage(MessageType msg)
{
	//mDelegates.push_back(*d);
	MessageDelegate *pDelegate = new MessageDelegate;
	mSubscribers[msg].push_back(pDelegate);
   //mSubscribers.insert(std::make_pair<MessageType,FastDelegate1<Message*> *>(msg,pDelegate));
	return pDelegate;
};

void MessageManager::UnSubscribeMessage(MessageType msg,void *pSubscriber)
{
	assert(bIsSending == false && msg != mSendMsg);
	for(std::vector<MessageDelegate *>::iterator it = mSubscribers[msg].begin(); it != mSubscribers[msg].end(); it++)
	{
		if((*it)->IsThis(pSubscriber))
		{
			mSubscribers[msg].erase(it);
			return;
		}
	}
	// if we get here, we tried to unsubscribe from a message that we hadnt subscribed to?
	assert(false);
	/*
	const std::pair<mapIterator,mapIterator> range = mSubscribers.equal_range(msg);
	for(mapIterator it = range.first; it != range.second && it->first == msg; ++it	)
	{
		if((it->second)->IsThis(pSubscriber))
		{
			mSubscribers.erase(it);
			return;
		}
	}
	*/

};

void MessageManager::PrintMessageInfo(const char *logtext,Message *pMsg)
{

}

// sends a message to all subscribers for a given message type.
// handles re-entrancy of message sending (probably quite badly right now)
// TODO: Create a proper crit section class for this..
void MessageManager::Send(unsigned int idSender,MessageType msgType,int iValue,void *pData,unsigned int idReciever)
{
	Message msg;
	msg.idSender = idSender;
	msg.idReciever = idReciever;
	msg.type = msgType;
	msg.iValue = iValue;
	msg.pData = pData;

	// use bIsSending as a sort of mutex
	if(bIsSending)
	{
		// sending already, so lets throw the message into a buffer and return
		mStoredMessages.push(msg);
		return;
	}

	// we are REALLY sending.. use this as a critical section
	bIsSending = true; mSendMsg = msgType;

	// send the message to all subscribers
	SendToSubscribers(&msg);

	bIsSending = false; mSendMsg = eMSG_NONE;

	unsigned int size = (unsigned int)mStoredMessages.size();
	// and then transmit any stored messages
	while ( !mStoredMessages.empty() )
	{
		Message *pMsg = &mStoredMessages.front();
		mStoredMessages.pop();
		PrintMessageInfo("Sending Stored Message: ",pMsg);
		// because sending can cause more messages so we need to crit sec this too..
		bIsSending = true; mSendMsg = pMsg->type;
		SendToSubscribers(pMsg);	
		bIsSending = false; mSendMsg = eMSG_NONE;
	}
};

void MessageManager::SendToSubscribers(Message *pMsg)
{/*
	mapIterator it;
	mapIterator last;
	// find returns iterator of first element for the given key
	it = mSubscribers.find(pMsg->type);
	// or returns iterator to end of map if key was empty
	if(it == mSubscribers.end()) return;
	// upper bound is last element in given key
	last = mSubscribers.upper_bound(pMsg->type);
	// iterate over the range
	for(; it != last; ++it	)
	{
		(it->second)->operator ()(pMsg);
	}
*/	
	MessageType type = pMsg->type;
	unsigned int size = mSubscribers[type].size();

	for(unsigned int i = 0; i < size; i++)
	{
		mSubscribers[type][i]->operator ()(pMsg);
	}

}


MessageType MessageListener::GetMessageTypeFromString(std::string str)
{

	return eMSG_ADDFOOD;
}