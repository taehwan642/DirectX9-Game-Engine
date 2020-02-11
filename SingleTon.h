#pragma once
template <class T>
class SingleTon
{
private:
	static T* _instance; // 인스턴스
public: // SingleTon의 자식으로 지정된 클래스들만 사용 가능한 키워드 (protected)
	static T* Instance()
	{
		if (_instance == nullptr) // 인스턴스가 없을 시엔
			_instance = new T(); // 새로운 인스턴스 생성
		return _instance; // 인스턴스 함수에게 반환
	}
};

template<class T>T* SingleTon<T>::_instance = nullptr;