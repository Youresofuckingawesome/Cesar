#pragma once

#include <cassert>
#include <iterator>

#include <container.h>

namespace Ces {

	template<typename __type>
	class List : public Container<__type>
	{
	public:
		List() = default;
		
		void Add(__type item) override;
		void Delete(__type item) override;
		void DeleteByIndex(unsigned int index) override;

		inline size_t Size() const override { return m_Cont.size(); }

		inline __type& GetElement(int index) override
		{
			auto listFront = m_Cont.begin();
			std::advance(listFront, index);
			return *listFront;
		}
		
	private:
		std::list<__type> m_Cont;
	};

	template<typename __type>
	void List<__type>::Add(__type item)
	{
		m_Cont.push_back(item);
	}

	template<typename __type>
	void List<__type>::Delete(__type item)
	{
		m_Cont.erase(std::remove(m_Cont.begin(), m_Cont.end(), item), m_Cont.end());
	}

	template<typename __type>
	void List<__type>::DeleteByIndex(unsigned int index)
	{
		auto listFront = m_Cont.begin();
		std::advance(listFront, index);
	    m_Cont.erase(listFront);
	}
	
}
