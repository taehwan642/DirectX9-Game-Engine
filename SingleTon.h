#pragma once
template <class T>
class Singleton
{
private:
	static T* ins;
public:
	static T* getins()
	{
		if (ins == nullptr)
			ins = new T();
		return ins;
	}
};

template <class T>T* Singleton<T>::ins = nullptr;
