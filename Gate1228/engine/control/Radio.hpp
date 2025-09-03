#pragma once
#include <stack>
#include <queue>
#include <list>

struct Message
{
	size_t from;
	size_t to;
	size_t content;

	Message(const size_t from, const size_t to,const size_t content): from(from),to(to),content(content){}
};

struct Envelope
{
	size_t from;
	size_t to;
	std::stack<size_t> contents;
	Envelope(const size_t from, const size_t to, std::stack<size_t> contents) : from(from), to(to),contents(std::move(contents))
	{
	}
};

class RadioDevice
{
public:
	virtual ~RadioDevice() = default;
	//base of any radio device
};

class Channel
{
	size_t num;
	Channel(size_t num) : num(num){}
};

class Radio
{
	std::queue<Message> messages_;
	std::queue<Envelope> envelopes_;
	std::list<Channel> channels_;
};

class Antenna : RadioDevice
{
	virtual bool send(Message msg) = 0;
	virtual bool recieve(Message msg) = 0;
};

class Reciever : RadioDevice
{
	virtual bool recieve(Message msg) = 0;
};

class Communicator : RadioDevice
{
	virtual bool send(Envelope env) = 0;
	virtual bool recieve(Envelope env) = 0;
};
