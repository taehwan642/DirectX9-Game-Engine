#pragma once
template <class T>
class Singleton
{
private:
	static T* minstance;
public:
	static T* GetIns() 
	{
		if (minstance == nullptr)
			minstance = new T();
		return minstance;
	}
};

template<class T> T* Singleton<T>::minstance = nullptr;