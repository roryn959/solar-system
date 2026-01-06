#pragma once

#include <cstddef>
#include <vector>

template <typename T>
class CircularBuffer {

    class Iterator {
    public:
        Iterator(const CircularBuffer& buffer, size_t pos, size_t count) : m_buffer{buffer}, m_pos{pos}, m_count{count} {};

        const T& operator*() const { return m_buffer[m_pos]; }

        Iterator& operator++() {
            m_pos = ++m_pos % m_buffer.GetCapacity();
            ++m_count;
            return *this;
        }

        bool operator!=(const Iterator& other) const { return m_count != other.m_count; }
        
    private:
        const CircularBuffer& m_buffer;
        size_t m_pos;
        size_t m_count;
    };

public:
    CircularBuffer(T t, int capacity) :
		m_array(capacity),
		m_head{0},
		m_size{0} 
	{
        for (int i=0; i < capacity; ++i) {
            Push(t);
        }
    }

    void Push(T t) {
        m_array[m_head] = t;
        m_head = (m_head + 1) % m_array.size();
        if (m_size < m_array.size())
            ++m_size;
    }

    inline size_t GetCapacity() const { return m_array.size(); }

    T& 			operator[](std::ptrdiff_t index) 			{ return m_array[index]; }
	const T& 	operator[](std::ptrdiff_t index) 	const	{ return m_array[index]; }

    Iterator begin()			{ return Iterator(*this, m_head, 0); }
    Iterator end()				{ return Iterator(*this, m_head, m_size); }
	Iterator begin()	const	{ return Iterator(*this, m_head, 0); }
    Iterator end()		const	{ return Iterator(*this, m_head, m_size); }

private:
    std::vector<T> m_array;
    size_t m_head;
    size_t m_size;

};