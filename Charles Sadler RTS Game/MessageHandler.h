#pragma once

class Message
{
public:
	int idMsg;
	int idSender;
	float value;
	void * data;
};

class MessageHandler
{
public:
	MessageHandler(void);
	~MessageHandler(void);
	virtual void HandleMessage(Message *pMsg) {};
};
