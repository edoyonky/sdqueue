#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

typedef struct data{
	int noPemain;
	string namaPemain;
	string posisiPemain;
	
}dData;

class simpul
{
	public :
		dData datapemain;
		simpul* pBerikutnya;
		
		
		simpul(string nam,string pos, int no)
		{
			datapemain.namaPemain = nam;
			datapemain.posisiPemain = pos;
			datapemain.noPemain = no;
			pBerikutnya = NULL;
		}
		
		void tampilSimpul()
		{
			cout << datapemain.noPemain << "--->" << datapemain.namaPemain << "--->" << datapemain.posisiPemain<<endl;
		}
};

class linkedlist
{
	private :
		simpul* pPertama;
		simpul* pAkhir;
	
	public :
		linkedlist() : pPertama(NULL)
		{}
		
		~linkedlist()
		{
			simpul* pSekarang = pPertama;
			while(pSekarang!=NULL)
			{
				simpul* pLama = pSekarang;
				pSekarang = pSekarang->pBerikutnya;
				delete pLama;
			}
		}
		
		bool apaKosong()
		{
			return (pPertama==NULL);
		}
		
		void sisipAkhir(string nam, string pos, int no)
		{
			simpul* pSimpulBaru = new simpul(nam,pos,no);
			if(apaKosong())
			{
				pPertama = pSimpulBaru;
			}
			else
			{
				pAkhir->pBerikutnya=pSimpulBaru;
			}
			pAkhir=pSimpulBaru;
		}
		
		void hapusPertama()
		{
			simpul* pTemp = pPertama;
			pPertama = pPertama->pBerikutnya;
			delete pTemp;
		}
		
		void tampilSenarai()
		{
			simpul* pSekarang = pPertama;
			if(pSekarang==NULL)
			{
				cout << "STACK KOSONG!!!";
			}
			while(pSekarang!=NULL)
			{
				pSekarang->tampilSimpul();
				pSekarang = pSekarang->pBerikutnya;
			}
			cout << endl;
		}
};

class queuelist
{
	private :
		linkedlist* pSenarai;
	
	public :
		queuelist()
		{
			pSenarai = new linkedlist;
		}
		
		~queuelist()
		{
			delete pSenarai;
		}
		
		void push(string nam, string pos, int no)
		{
			pSenarai->sisipAkhir(nam,pos,no);
		}
		
		void pop()
		{
			pSenarai->hapusPertama();	
		}
		
		bool apaKosong()
		{
			return (pSenarai->apaKosong());
		}
		
		void tampilTumpukan()
		{
			pSenarai->tampilSenarai();
		}
};

int main()
{
	queuelist queue;
	int pilih, no;
	string nama, posisi;
	do 
	{
		cout << "          Data Pemain Sepakbola";
		cout << "\n============================================" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Tampil Data" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Masukkan Pilihan Anda : ";
		cin >> pilih;
		cout << "=====================================================" << endl;
	
		switch(pilih)
		{
			case 1 :
				cout << "\nNomer Punggung Pemain : "; cin >> no;
				cin.ignore(256,'\n');
				cout << "Nama Pemain : "; getline(cin,nama);
				cout << "Posisi Pemain : "; getline(cin,posisi);
				queue.push(nama,posisi,no);
				break;
				
			case 2 :
				queue.pop();
				break;
			
			case 3 :
				queue.tampilTumpukan();
				break;
				
			case 4 :
				exit(0);
				break;
				
			default :
				cout << "pilihan salah!!!"<<endl;
		}
	} while (true);
	getch();
	return 0;
}
