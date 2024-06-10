#include <iostream>
#include <vector>
using namespace std;


class Perusahaan;
class karyawan {
public:
	string namakaryawan;
	vector<karyawan*> daftar_karyawan;
	karyawan(string pNama) : namakaryawan(pNama) {
		cout << "karyawan \"" << namakaryawan << "\" ada\n";
	}
	~karyawan() {
		cout << "karyawan \"" << namakaryawan << "\" tidak ada\n";
	}
	void tambahkaryawan(karyawan*);
	void cetakkaryawan();
};


class proyek {
public:
	string namaproyek, jenis;
	vector<proyek*> daftarproyek;

	proyek(string pNama) : jenis(pNama) {
		cout << "proyek \"" << namaproyek << "\"  ada\n";
	}
	~proyek() {
		cout << "proyek \"" << namaproyek << "\" tidak ada\n";
	}
	void tambahproyek(proyek*);
	void cetakproyek();

};

void karyawan::tambahkaryawan(karyawan* pKaryawan) {  
	daftar_karyawan.push_back(pKaryawan);   
}

void karyawan::cetakkaryawan() {  
	cout << "----------------------------------" << endl;
	cout << "Daftar karyawan yang mengerjakan proyek" << this-> namakaryawan << " : " << endl;
	for (auto& a : daftar_karyawan) {  
		cout << a->namakaryawan << endl;
	}
	cout << "----------------------------------" << endl;
	cout << endl;
}

void proyek::tambahproyek(proyek* pProyek) {  
	daftar_Proyek.push_back(pProyek);
}

void proyek::cetakproyek() { 
	cout << "----------------------------------" << endl;
	cout << "Proyek " << this->namaproyek << " dikerjakan karyawan: " << endl;
	for (auto& a : daftar_proyek) {
		cout << a->nama_proyek << endl;
	}
	cout << "----------------------------------" << endl;
	cout << endl;
}


int main() {
	karyawan* varkaryawan1 = new karyawan("Budi");
	karyawan* varkaryawan2 = new karyawan("Andi");
	proyek* varproyek1 = new proyek("Sistem informasi");
	proyek* varproyek2 = new proyek("Sistem keamanan");

	varkaryawan1->tambahkaryawan(varproyek1);
	varkaryawan1->tambahkaryawan(varproyek2);
	varkaryawan2->tambahkaryawan(varproyek1);

	varkaryawan1->cetakProyek();
	varkaryawan2->cetakProyek();
	varproyek1->cetakKaryawan();
	varproyek2->cetakKaryawan();

	delete varproyek1;
	delete varproyek2;
	delete varkaryawan1;
	delete varkaryawan2;

	return 0;
}

