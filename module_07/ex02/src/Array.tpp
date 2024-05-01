/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:27:53 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/01 17:05:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
	std::cout << CYAN("Constructor allocated an array with size 0") \
		<< std::endl;
}

template <typename T>
Array<T>::Array(const unsigned int &n) : _array(new T[n]), _size(n)
{
	std::cout << CYAN("Constructor allocated an array with size " << n) \
	 << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
	std::cout << CYAN("Destructor deleted the array") << std::endl;
}

template <typename T>
Array<T>::Array(const Array &rhs) : _array(new T[0]), _size(0)
{
	std::cout << CYAN("Copy constructor called") << std::endl;
	*this = rhs;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return this->_size;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs)
{
	std::cout << CYAN("'=' operator overload called") << std::endl;
	if (this != &rhs)
	{
		delete [] this->_array;
		const unsigned int n = rhs.size();
		this->_array = new T[n];
		this->_size = rhs.size();
		for (unsigned int i = 0; i < n; i++)
		{
			this->_array[i] = rhs._array[i];
		}
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](const unsigned int &index) const
{
	if (index >= this->_size) {
		throw std::out_of_range("Index out of range");
	}
	return this->_array[index];
}

template <typename T>
T&	Array<T>::operator[](const unsigned int &index)
{
	if (index >= this->_size) {
		throw std::out_of_range("Index out of range");
	}
	return this->_array[index];
}

template <typename T>
std::ostream &operator<<(std::ostream &lhs, const Array<T> &rhs)
{
	const unsigned int	n = rhs.size();

	lhs << "ARRAY { ";

	for (unsigned int i = 0; i < n; i++)
	{
		lhs << rhs[i];
		if (i != n - 1)
		{
			lhs << ", ";
		}
	}
	lhs << " }";
	return lhs;
}
