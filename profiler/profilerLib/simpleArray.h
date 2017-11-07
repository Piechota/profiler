#ifndef SIMPLE_ARRAY_H
#define SIMPLE_ARRAY_H

namespace Profiler
{
	template <class T>
	class TSimpleArray
	{
	private:
		T* m_data;
		unsigned int m_arraySize;
		unsigned int m_size;

	public:
		TSimpleArray()
			: m_data( nullptr )
			, m_arraySize( 0 )
			, m_size( 0 )
		{}

		TSimpleArray(unsigned int const size)
			: m_data( nullptr )
			, m_arraySize( 0 )
			, m_size( 0 )
		{
			Reserve( size );
		}

		~TSimpleArray()
		{
			if ( m_data )
			{
				delete[] m_data;
			}

			m_data = nullptr;
			m_arraySize = 0;
			m_size = 0;
		}

		void Resize( unsigned int const size )
		{
			if ( m_arraySize < size )
			{
				T* pTmp = new T[ size ];

				if ( m_data )
				{
					if ( m_size )
					{
						unsigned int const cpySize = min( m_size, size );
						memcpy( pTmp, m_data, cpySize * sizeof( T ) );
					}

					delete[] m_data;
				}

				m_arraySize = size;
				m_data = pTmp;
			}

			m_size = size;
		}

		void Reserve( unsigned int const size )
		{
			if ( m_arraySize < size )
			{
				T* pTmp = new T[ size ];

				if ( m_data )
				{
					if ( m_size )
					{
						unsigned int const cpySize = min( m_size, size );
						memcpy( pTmp, m_data, cpySize * sizeof( T ) );
					}

					delete[] m_data;
				}

				m_arraySize = size;
				m_data = pTmp;
			}
		}

		void Clear()
		{
			m_size = 0;
		}

		void PushBack( T const& elem )
		{
			if ( m_size == m_arraySize )
			{
				Reserve( ( m_size + 1 ) * 2 );
			}

			m_data[ m_size ] = elem;
			++m_size;
		}

		T* Begin()
		{
			return m_data;
		}

		T* End()
		{
			return m_data[ m_size ];
		}

		unsigned int Size() const
		{
			return m_size;
		}
	};
}
#endif //SIMPLE_ARRAY_H
