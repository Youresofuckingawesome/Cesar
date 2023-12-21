#include <array.h>

#include <cassert>

namespace Ces {

	template<typename __type, unsigned int __capacity>
	void Array<__type, __capacity>::Add(__type item)
	{
		assert(true && "Array doesn't have Add method!");
	}

	template<typename __type, unsigned int __capacity>
	void Array<__type, __capacity>::Delete(__type item)
	{
		assert(true && "Array doesn't have Delete method!");
	}

	template<typename __type, unsigned int __capacity>
	void Array<__type, __capacity>::DeleteByIndex(unsigned int index)
	{
		assert(true && "Array doesn't have DeleteByIndex method!");
	}

	template<typename __type, unsigned int __capacity>
	__type Array<__type, __capacity>::operator[](unsigned int index) const
	{
		return m_Cont[index];
	}

	template<typename __type, unsigned int __capacity>
	__type& Array<__type, __capacity>::operator[](unsigned int index)
	{
		return &m_Cont[index];
	}
}
