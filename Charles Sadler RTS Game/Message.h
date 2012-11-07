#pragma once
#include <vector>
#include <map>
#include <queue>
#undef SendMessage
#include "FastDelegate.h"

using namespace fastdelegate;

enum MessageType
{
	eMSG_NONE,
	eMSG_STARTGAME,
	eMSG_SELECTALL,
	eMSG_SELECTNONE,
	eMSG_SELECTIONCHANGED,
	eMSG_SELECTIONGOBIDCHANGED,
	eMSG_HIGHLIGHTCHANGED,
	eMSG_MOUSERAYHIT,
	eMSG_MOUSEPRESSEDONOBJECT,
	eMSG_MOUSERELEASEDONOBJECT,
	eMSG_SELECTIONLISTCHANGED,
	eMSG_SQUADSELECTIONCHANGED,
	eMSG_SQUADSELECT,
	eMSG_SQUADMOVETOLOCATION,
	eMSG_SQUADMEMBERFOLLOWTEAMMATE,
	eMSG_MOUSEPRESSED,
	eMSG_MOUSEMOVED,
	eMSG_MOUSEWHEELMOVED,
	eMSG_MOUSERELEASED,
	eMSG_KEYRELEASED,
	eMSG_SELECTEDMOVETOLOCATION,
	eMSG_MOVETOLOCATION,
	eMSG_MOVECOMPLETE,
	eMSG_STOPMOVING,
	eMSG_CREATETESTSCENE,
	eMSG_ANIMATIONSTART,
	eMSG_ANIMATIONSTOP,
	eMSG_COLLISION,
	eMSG_PICKUPOBJECT,
	eMSG_OBJECTPICKEDUP,
	eMSG_DROPOBJECT,
	eMSG_GIVEOBJECT,
	eMSG_REFUSEGIFT,
	eMSG_ACCEPTGIFT,
	eMSG_SHOWICON,
	eMSG_USEREQUEST,
	eMSG_USEREQUESTREPLY,
	eMSG_USEREQUESTDENIED,
	eMSG_USEREQUESTACCEPTED,
	eMSG_ADDSOCIAL,
	eMSG_ADDGOD,
	eMSG_ADDHEALTH,
	eMSG_ADDDRINK,
	eMSG_ADDFOOD,
	eMSG_NEXTCREATE,
	eMSG_PREVCREATE,
	eMSG_SHOWCREATECURSOR,
	eMSG_SHOWACTIONCURSOR,
	eMSG_HIDEACTIONCURSOR,
	eMSG_CREATECURRENTFROMTEMPLATE,
	eMSG_DEBUGDRAW,
	eMSG_NAVPATHALLOCREQUEST,
	eMSG_NAVPATHALLOCATED,
	eMSG_NAVPATHREQUEST,
	eMSG_NAVPATHREQUESTCOMPLETE,
	eMSG_INSERTBRAIN,
	eMSG_CLEARBRAIN,
	eMSG_CHARACTER_COLLISION,
	eMSG_SETSQUAD,
	eMSG_ADDSQUADMEMBER,
	eMSG_REMOVESQUADMEMBER,
	eMSG_ACTIONPROTECT,
	eMSG_ACTIONATTACK,
	eMSG_ACTIONINVESTIGATE,
	eMSG_ACTIONMOVETO,
	eMSG_TAKEDAMAGE,
	eMSG_TRIGGERDOWN,
	eMSG_TRIGGERUP,
	eMSG_DRAWUI,
	eMSG_SAVETOFILE,
	eMSG_NEXTITEMININVENTORY,
	eMSG_PREVITEMININVENTORY,
	eMSG_SELECTINVENTORYITEM,
	eMSG_CLEARHELDINVENTORYITEM,
	eMSG_SWITCHWEAPON,
	eMSG_WORKAVAILABLE,
	eMSG_HOMEAVAILABLE,
	eMSG_TRANQUILIZED,
};

// the "Message" data type (note: 16 bytes so hopefully we can align it)
// but, as we're storing it in a vector right now, it wont, but we can
// replace the vector once we know the max rate of messages etc.
// TODO: perhaps add some method of knowing how many messages we send?
struct Message
{
	MessageType type;
	unsigned int idSender;
	unsigned int idReciever;
	int iValue;
	void * pData;
};

// the base class for a message handler class. Most classes that do useful things
// will derive from this at some level
class MessageListener
{
public:
	MessageListener();
	~MessageListener();
	virtual bool HandleMessage(Message *pMessage);
   void Send(unsigned int idSender,MessageType msgType,int iValue,void *pData,unsigned int idReciever = 0);
   MessageType GetMessageTypeFromString(std::string str);
};

typedef FastDelegate1<Message *> MessageDelegate;


// the global singleton message relay manager system doobry
class MessageManager 
{
	bool bIsSending;
	MessageType mSendMsg;
	std::vector<MessageDelegate> mDelegates;
	std::map<MessageType,std::vector<MessageDelegate *>> mSubscribers;
	//std::multimap<MessageType,FastDelegate1<Message*> *> mSubscribers;

   typedef std::multimap<MessageType,FastDelegate1<Message*> *>::iterator mapIterator;
   std::queue<Message> mStoredMessages;
	MessageManager();
	~MessageManager();
public:
	static MessageManager& GetInstance() { static MessageManager theMessageManager; return theMessageManager; };
	MessageDelegate* SubscribeMessage(MessageType msg);
	void UnSubscribeMessage(MessageType msg, void *pSubscriber);
   void Send(unsigned int idSender,MessageType msgType,int iValue,void *pData,unsigned int idReciever = 0);
	void SendToSubscribers(Message *pMsg);
	void PrintMessageInfo(const char *logtext,Message *pMsg);

};

