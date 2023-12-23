#pragma once

#include <algorithm>

#include <container.h>

namespace Ces {

	template<typename __type>
	class Vector : public Container<__type>
	{
	public:
		Vector() = default;

		void Add(__type item) override;
		void Delete(__type item) override;
		void DeleteByIndex(unsigned int index) override;

		inline size_t Size() const override { return m_Cont.size(); }

		inline __type& GetElement(int index) override { return m_Cont[index]; }
		
	private:
		std::vector<__type> m_Cont;
	};

	template<typename __type>
	void Vector<__type>::Add(__type item)
	{
		m_Cont.push_back(item);
	}

	template<typename __type>
	void Vector<__type>::Delete(__type item)
	{
		m_Cont.erase(std::remove(m_Cont.begin(), m_Cont.end(), item), m_Cont.end());
	}

	template<typename __type>
	void Vector<__type>::DeleteByIndex(unsigned int index)
	{
		m_Cont.erase(m_Cont.begin() + index);
	}

}
