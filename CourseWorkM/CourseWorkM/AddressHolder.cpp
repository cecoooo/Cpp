#include "AddressHolder.h"
using std::cout;

AddressHolder::AddressHolder() 
{
	if (this->getAddress() != NULL)
	{
		this->adr[0] = this->getAddress();
		this->currentLenght = 1;
	}
	else
		this->currentLenght = 0;
}

AddressHolder::~AddressHolder()
{
	for (size_t i = 0; i < currentLenght; i++)
	{
		if (this->adr[i] != NULL)
		{
			free(this->adr[i]);
			this->adr[i] = NULL;
		}
	}
}

void AddressHolder::addAddress(char * address, int len) 
{
	if (currentLenght == MaxLength)
		cout << "A person is not allowed to possess more than five Address.";
	else 
	{
		char* newAdr = (char*)malloc(len);
		strcpy_s(newAdr,len, address);
		this->adr[currentLenght] = newAdr;
		this->currentLenght++;
	}
}
