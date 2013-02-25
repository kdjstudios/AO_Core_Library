/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOVECTOR_H
#define AOVECTOR_H

namespace ao
{
	namespace core
	{
		//
		// Allocator
		// (class template)
		// ----------
		// + allocate(size_t):TYPE*
		// ----------
		// + deallocate(TYPE*, size_t): void
		// + construct(TYPE*, size_t): void
		// + destroy(TYPE*, size_t): void
		// ----------
		//
		template <class TYPE> class Allocator
		{
		public:
			TYPE* allocate(size_t);
			void deallocate(TYPE*, size_t);
			void construct(TYPE*,TYPE);
			void destroy(TYPE*);

		};
		//
		// Vector
		// (class template)
		// ----------
		// + iterator :typedef TYPE*
		// + const_iterator :typedef const TYPE*
		// + sizetype :typedef size_t
		// + value_type :typedef TYPE
		// + 	Vector()
		// + 	explicit Vector(size_type n, const TYPE& t=TYPE())
		// + 	Vector(const Vector& v)
		// + 	Vector& operator=(const Vector&);
		// + 	~Vector()

		// + 	TYPE& operator[] (size_type i)
		// + 	const TYPE& operator[] (size_type i)const
		// + 	void push_back(const TYPE& t)

		// + 	size_type size() const
		// + 	iterator begin()
		// + 	const_iterator begin() const
		// + 	iterator end()
		// + 	const_iterator end() const
		// ----------
		// - data: iterator
		// - avail: iterator
		// - limit: iterator
		// - alloc:Allocator<TYPE>
		// - create():void
		// - create(size_type,const TYPE&):void
		// - create(const_iterator, const_iterator):void
		// - uncreate():void
		// - grow():void
		// - unchecked_append(const TYPE&):void
		// ----------
		//
		template <class TYPE> class Vector
		{
		public:
			typedef TYPE* iterator;
			typedef const TYPE* const_iterator;
			typedef size_t size_type;
			typedef TYPE value_type;

			Vector()
			{
				create();
			}
			explicit Vector(size_type n, const TYPE& t=TYPE())
			{
				create(n,t);
			}

			Vector(const Vector& v)
			{
				create(v.begin(),v.end());
			}
			Vector& operator=(const Vector&);
			~Vector()
			{
				uncreate();
			}

			TYPE& operator[] (size_type i)
			{
				return data[i];
			}
			const TYPE& operator[] (size_type i)const
			{
				return data[i];
			}

			void push_back(const TYPE& t)
			{
				if(avail==limit)
					grow();
				unchecked_append(t);
			}

			size_type size() const
			{
				return avail-data;
			}
			iterator begin()
			{
				return data;
			}
			const_iterator begin() const
			{
				return data;
			}
			iterator end()
			{
				return avail;
			}
			const_iterator end() const
			{
				return avail;
			}
		private:
			iterator data;
			iterator avail;
			iterator limit;

			Allocator<TYPE> alloc;

			void create();
			void create(size_type,const TYPE&);
			void create(const_iterator, const_iterator);

			void uncreate();
			void grow();
			void unchecked_append(const TYPE&);

		};
		//Vector
		template <class T> void Vector<T>::create()
		{
			data = avail = limit = 0;
		}
		template <class T> void Vector<T>::create(size_type n, const T& val)
		{
			data = alloc.allocate(n);
			limit = avail =  data+n;
			//uninitialized_fill(data,limit,val);
		}
		template <class T> void Vector<T>::create(const_iterator i, const_iterator j)
		{
			data = alloc.allocate(j-i);
			//avail = limit = unintialized_copy(i,j,data);
		}
		template <class T> void Vector<T>::uncreate()
		{
			if(data )
			{
				iterator it=avail;
				while (it!=0)
					alloc.destory(--it);

				alloc.dellocate(data,limit-data);
			}
			data=limit=avail=0;
		}
		template <class T> void Vector<T>::grow()
		{
			size_type new_size=max(2* (limit-data),ptrdiff_t(1));
			iterator new_data = alloc.allocate(new_size);
			iterator new_avail=unitilized_copy(data,avail,new_data);

			uncreate();
			data=new_data;
			avail=new_avail;
			limit=data+new_size;
		}
		template <class T> void Vector<T>::unchecked_append(const T& val)
		{
			alloc.construct(avail++,val);
		}
		//excess str function
		template <class T> Vector<T>* clone(const Vector<T>* vp)
		{
			return new Vector<T>(*vp);
		}
	}
}
#endif
