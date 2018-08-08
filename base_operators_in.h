#pragma once

#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <initializer_list>

template<class TIterator>
struct OpInResult
{
	bool m_result;
	TIterator m_iter;
public:
	OpInResult(bool result, TIterator& iter)
		: m_result(result), m_iter(iter)
	{}

	operator bool()
	{
		return m_result;
	}

	TIterator& operator->()
	{
		return m_iter;
	}

	TIterator& data()
	{
		return m_iter;
	}
};


template<class TKey, class TVal>
auto operator_in(const TKey& key, std::unordered_map<TKey, TVal>& data) -> OpInResult<typename std::unordered_map<TKey, TVal>::iterator>
{
	auto iter = data.find(key);
	return OpInResult<typename std::unordered_map<TKey, TVal>::iterator>(iter != data.end(), iter);
}

template<class TKey, class TVal>
auto operator_in(const char* key, std::unordered_map<TKey, TVal>& data) -> OpInResult<typename std::unordered_map<TKey, TVal>::iterator>
{
	auto iter = data.find(key);
	return OpInResult<typename std::unordered_map<TKey, TVal>::iterator>(iter != data.end(), iter);
}

template<class TKey, class TVal>
auto operator_in(const TKey& key, std::map<TKey, TVal>& data) -> OpInResult<typename std::map<TKey, TVal>::iterator>
{
	auto iter = data.find(key);
	return OpInResult<typename std::map<TKey, TVal>::iterator>(iter != data.end(), iter);
}

template<class TKey, class TVal>
auto operator_in(const char* key, std::map<TKey, TVal>& data) -> OpInResult<typename std::map<TKey, TVal>::iterator>
{
	auto iter = data.find(key);
	return OpInResult<typename std::map<TKey, TVal>::iterator>(iter != data.end(), iter);
}

template<class TKey>
bool operator_in(const TKey& key, std::unordered_set<TKey>& data)
{
	return data.find(key) != data.end();
}

template<class TKey>
bool operator_in(const char* key, std::unordered_set<TKey>& data)
{
	return data.find(key) != data.end();
}

template<class TKey>
bool operator_in(const TKey& key, std::set<TKey>& data)
{
	return data.find(key) != data.end();
}

template<class TKey>
bool operator_in(const char* key, std::set<TKey>& data)
{
	return data.find(key) != data.end();
}

bool operator_in(const std::string& key, const std::string& data)
{
	return data.find(key) != std::string::npos;
}

template<class TKey>
bool operator_in(const TKey& key, const std::initializer_list<TKey>& data)
{
	return std::find(data.begin(), data.end(), key) != data.end();
}
template<class TKey>
bool operator_in(const char* key, const std::initializer_list<TKey>& data)
{
	return std::find(data.begin(), data.end(), key) != data.end();
}

template<class TKey>
bool operator_in(const TKey& key, const std::vector<TKey>& data)
{
	return std::find(data.begin(), data.end(), key) != data.end();
}
template<class TKey>
bool operator_in(const char* key, const std::vector<TKey>& data)
{
	return std::find(data.begin(), data.end(), key) != data.end();
}