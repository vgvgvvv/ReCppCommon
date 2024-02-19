#pragma once
#include <cstdint>
#include <map>
#include <mutex>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <cassert>
#include <functional>


#if USE_REMAKE
#include "ReCppCommon_API.h"
#endif

#ifndef RECPPCOMMON_API
	#ifdef ReCppCommon_API
		#define RECPPCOMMON_API ReCppCommon_API
	#else
		#define RECPPCOMMON_API
	#endif
#endif

#define RE_INLINE inline

#define DEFINE_NUMBER_TYPE(NUMTYPE) \
using NUMTYPE = NUMTYPE##_t;

	DEFINE_NUMBER_TYPE(int8)
	DEFINE_NUMBER_TYPE(int16)
	DEFINE_NUMBER_TYPE(int32)
	DEFINE_NUMBER_TYPE(int64)
	DEFINE_NUMBER_TYPE(uint8)
	DEFINE_NUMBER_TYPE(uint16)
	DEFINE_NUMBER_TYPE(uint32)
	DEFINE_NUMBER_TYPE(uint64)

#undef DEFINE_NUMBER_TYPE

namespace Re
{
	using String = std::string;
	template<typename FN>
	using Func = std::function<FN>;
	template<typename T>
	using Vector = std::vector<T>;
	template<typename K, typename V>
	using Map = std::map<K, V>;
	template<typename Item1, typename Item2>
	using Pair = std::pair<Item1, Item2>;
	template<typename T>
	using Queue = std::queue<T>;
	template<typename T>
	using Stack = std::stack<T>;

#define RE_MAKE_PAIR std::make_pair
#define RE_GET_FROM_PAIR(PAIR, COUNT) std::get<COUNT>(PAIR)

	template<typename T>
	using LockGuard = std::lock_guard<T>;
	using Mutex = std::mutex;
	using DefaultLockGuard = LockGuard<Mutex>;

	template<typename T>
	using SharedPtr = std::shared_ptr<T>;
#define RE_MAKE_SHARED(T) std::make_shared<T>
	template<typename T>
	RE_INLINE T* SharedPtrGet(const SharedPtr<T>& Ptr)
	{
		return Ptr.get();
	}

	template<typename TTo, typename TFrom>
	RE_INLINE SharedPtr<TTo>* SharedPtrCast(const SharedPtr<TFrom>& Ptr)
	{
		return std::static_pointer_cast<TTo>(Ptr);
	}

	template<typename T>
	using WeakPtr = std::weak_ptr<T>;

	template<typename T>
	RE_INLINE T* WeakPtrGetSafe(const WeakPtr<T>& Ptr)
	{
		if(Ptr.expired())
		{
			return nullptr;
		}
		return Ptr.lock().get();
	}

	template<typename T>
	RE_INLINE bool WeakPtrValid(const WeakPtr<T>& Ptr)
	{
		return !Ptr.expired() || Ptr.lock() != nullptr;
	}


	template<typename T>
	using UniquePtr = std::unique_ptr<T>;

#define RE_MAKE_UNIQUE(T) std::make_unique<T>

#define RE_ASSERT(x) assert(x)
#define RE_LOG(x) ILogger::Get().Log((x));
#define RE_WARN(x) ILogger::Get().Warn(x);
#define RE_ERROR(x) ILogger::Get().Error(x);
#define RE_MOVE(x) std::move(x)

}


#include "Log/Logger.h"
#include "Log/Assert.h"
#include "Macro/CoreMacros.h"