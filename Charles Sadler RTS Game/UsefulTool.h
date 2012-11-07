#pragma once
#include <map>
#include <string>

class Storage
{
private:
	std::map< std::string, void* > m_Container;

	Storage(){}
	~Storage(){}

public:
	static Storage& GetSingleton(){ static Storage store; return store; }
	static Storage* GetSingeltonPtr(){ return &Storage::GetSingleton(); }

	void AddItem(std::string name, void* thing)
	{
		auto it = m_Container.find(name);
		auto end = m_Container.end();

		if (it != end) return;

		m_Container.insert( std::make_pair(name, thing) );
	}

	void RemoveItem(std::string name)
	{
		auto it = m_Container.find(name);
		auto end = m_Container.end();

		if (it != end)
			m_Container.erase(it);
	}

	void* GetItem(std::string name)
	{
		auto it = m_Container.find(name);
		auto end = m_Container.end();

		if (it != end)
			return it->second;

		return 0;
	}
};

#define STORAGE Storage::GetSingelton()
#define STORAGEPTR Storage::GetSingletonPtr()