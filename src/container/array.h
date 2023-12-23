#pragma once

#include <cassert>

#include <container.h>

namespace Ces {

	template<typename __type, unsigned int __capacity>
	class Array : public Container<__type>
	{
	public:
		Array() = default;

		void Add(__type item) override;
		void Delete(__type item) override;
		void DeleteByIndex(unsigned int index) override;

		inline size_t Size() const override { return m_Cont.size(); }

		inline __type& GetElement(int index) override { return m_Cont[index]; }
		
	private:
		std::array<__type, __capacity> m_Cont;
		int m_Stored = 0;
	};

	template<typename __type, unsigned int __capacity>
	void Array<__type, __capacity>::Add(__type item)
	{
		if (m_Stored > m_Cont.size())
			assert(false && "Stored bigger then size");
	    m_Cont[m_Stored++] = item;
	}

	template<typename __type, unsigned int __capacity>
	void Array<__type, __capacity>::Delete(__type item)
	{
		assert(false && "Array doesn't have Delete method!");
	}

	template<typename __type, unsigned int __capacity>
	void Array<__type, __capacity>::DeleteByIndex(unsigned int index)
	{
		assert(false && "Array doesn't have DeleteByIndex method!");
	}

}
