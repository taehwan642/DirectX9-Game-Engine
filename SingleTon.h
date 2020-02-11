#pragma once
template <class T>
class SingleTon
{
private:
	static T* _instance; // �ν��Ͻ�
public: // SingleTon�� �ڽ����� ������ Ŭ�����鸸 ��� ������ Ű���� (protected)
	static T* Instance()
	{
		if (_instance == nullptr) // �ν��Ͻ��� ���� �ÿ�
			_instance = new T(); // ���ο� �ν��Ͻ� ����
		return _instance; // �ν��Ͻ� �Լ����� ��ȯ
	}
};

template<class T>T* SingleTon<T>::_instance = nullptr;