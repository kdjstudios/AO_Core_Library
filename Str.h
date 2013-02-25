/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOSTR_H
#define AOSTR_H



#include <iostream>
#include "aoRefPtrHandle.h"
//#include "Vector.h"
namespace ao
{
	namespace core
	{
		//
		// Str
		// (class template)
		// ----------
		// + size_type : Vector<char>::size_type
		// + up:BSTNode<TYPE>*
		// + left:BSTNode<TYPE>*
		// + size() :size_type
		// ----------
		// - data :Ptr< Vector<char> >
		// ----------
		// + Str()
		// + Str( const char* cp)
		// + Str( size_type n, char cp)
		// ----------
		//
		class Str
		{
			friend std::istream& operator>>(std::istream&,Str&);
		private:
			Ptr< Vector<char> > data;
		public:
			//Find
			//append/assign/clear/copy/erase/insert/push_back/replace/resize/swap
			//Backend Stuff?
			Str& operator+=(const Str& s)
			{
				data.make_unique();
				//copy(s.data->begin(),s.data->end(), std::back_inserter(*data));
				return *this;
			}
			typedef Vector<char>::size_type size_type;

			Str(): data(new Vector<char>) {}
			Str(const char* cp): data(new Vector<char>)
			{
				//copy(cp,cp+std::strlen(sp),std::back_inserter(*data));
			}
			Str(size_type n, char c): data(new Vector<char>(n,c)) {}
			template<class I> Str(I i, I j):data(new Vector<char>)
			{
				//copy(i,j,std::back_inseter(*data));
			}
			char& operator[](size_type i)
			{
				data.make_unique();
				return (*data)[i];
			}
			const char& operator[](size_type i) const
			{
				return (*data)[i];
			}
			size_type size() const
			{
				return data->size();
			}

		};
		std::ostream& operator<<(std::ostream&, const Str&);
		Str operator+(const Str&, const Str&);


	}
}
#endif
