#pragma once
template <class T>
class SingleTon
{
private:
	static T* instance;
public:
	static T* getInstance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
};

template <class T> T* SingleTon<T>::instance = nullptr;

class Time
{
public:
	static float deltatime;
	static float timescale;
};