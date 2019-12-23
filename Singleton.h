#pragma once

template <class T>
class Singleton
{
private:
	static T* instance;
public:
	static T* Getinstance()
	{
		if (instance == null)
			instance = new T();

		return instance;
	}
};

template <class T>  T* Singleton<T>::instance = nullptr;

class Time
{
public:
	static float deltatime;
	static float timescale;
};