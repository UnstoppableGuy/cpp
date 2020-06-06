//---------------------------------------------------------------------------


#pragma hdrstop

#include "Hash.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool Hash::IsExist(int Key)
{
	int i = Key % 20;
	Node* node = hashstack[i].Head;
	while (node != NULL)
	{
		if (node->key == Key) {
			return true;
		}
		node = node->Next;
	}
	return false;
}
bool Hash::AddToHash(int key)
{
	 if  (IsExist(key) == true || key == 0) {
		return false;
	}
	int i = key % 20;
	 hashstack[i].Push(key);
	 return true;
}
bool Hash::DeleteFromHash(int key)
{
	if (IsExist(key) == false|| key == 0) {
		return false;
	}
	 int i = key % 20;
	 hashstack[i].Delete(key);
	 return true;
}

 void Hash::DeleteAll()
 {
	for (int i = 0; i < 20; i++) {
		   hashstack[i].Head->key = -1;
		   Node *temp = hashstack[i].Head;
		   while (temp != NULL)
		   {
			 Node *temp2 = temp;
			 temp = temp->Next;
			 delete temp2;
		   }
	}
 }

