#include <stdio.h>
#include <iostream>

using namespace std;
class air{

float ph_asam = 0;
float ph_normal = 0;
float ph_basa = 0;
float warna_jernih = 0;
float warna_sedang = 0;
float warna_kuning = 0;
float tds_rendah = 0;
float tds_sedang = 0;
float tds_tinggi = 0;
float tercemar_ringan [100];
float normal [100];
float tercemar_berat [100];
float hasil_normal;
float hasil_tercemar_ringan;
float hasil_tercemar_berat;
float crispOutput;


public:

    //keanggotaan PH
    void anggota_ph(float PH){

    if (PH>=0 && PH <7){
        if (PH >= 0 && PH <= 6){
            ph_asam = 1;
        }
        else if (PH > 6 && PH < 7){
            ph_asam = (float)((7-PH)/(7-6));
        }
        cout<<"PH Asam =\t"<<ph_asam<<endl;
    }
    if (PH > 6 && PH < 9){
        if (PH > 6 && PH < 7){
            ph_normal = (float)((PH-6)/(7-6));
        }
        else if (PH >= 7 && PH <= 8){
            ph_normal = 1;
        }
        else if (PH > 8 && PH < 9){
            ph_normal = (float)((8-PH)/(8-9));
        }
        cout<<"PH Normal =\t"<<ph_normal<<endl;
    }
    if (PH > 8 && PH <= 14){
        if (PH > 8 && PH < 9){
            ph_basa = (float)((PH-8)/(9-8));
        }
        else if (PH >= 9 && PH <= 14){
            ph_basa = 1;
        }
        cout<<"PH BASA =\t"<<ph_basa<<endl;
    }
    }

    //keanggotaan Warna
    void anggota_warna(float WARNA){

    if (WARNA >=0 && WARNA < 60){
        if (WARNA >= 0 && WARNA <= 50){
            warna_jernih = 1;
        }
        else if (WARNA > 50 && WARNA < 60){
            warna_jernih = (float)((60-WARNA)/(60-50));
        }
        cout<<"Warna Jernih =\t"<<warna_jernih<<endl;
    }
    if (WARNA > 50 && WARNA < 70){
        if (WARNA > 50 && WARNA < 60){
            warna_sedang = (float)((WARNA-50)/(60-50));
        }
        else if (WARNA == 60){
            warna_sedang = 1;
        }
        else if (WARNA > 60 && WARNA < 70){
            warna_sedang = (float)((70-WARNA)/(70-60));
        }
        cout<<"Warna Sedang =\t"<<warna_sedang<<endl;
    }
    if (WARNA > 60){
        if (WARNA > 60 && WARNA < 70){
            warna_kuning = (float)((WARNA-60)/(70-60));
        }
        else if (WARNA >= 70){
            warna_kuning = 1;
        }
        cout<<"Warna Keruh =\t"<<warna_kuning<<endl;
    }

    }

    //keanggotaan TDS
    void anggota_tds(float TDS){

    if (TDS>=0 && TDS < 1750){
        if (TDS >= 0 && TDS <= 1500){
            tds_rendah = 1;
        }
        else if (TDS > 1500 && TDS < 1750){
            tds_rendah = (float)((1750-TDS)/(1750-1500));
        }
        cout<<"TDS Rendah =\t"<<tds_rendah<<endl;
    }
    if (TDS > 1500 && TDS < 2000){
        if (TDS > 1500 && TDS < 1750){
            tds_sedang = (float)((TDS-1500)/(1750-1500));
        }
        else if (TDS == 1750){
            tds_sedang = 1;
        }
        else if (TDS > 1750 && TDS < 2000){
            tds_sedang = (float)((2000-TDS)/(2000-1750));
        }
        cout<<"TDS sedang =\t"<<tds_sedang<<endl;
    }
    if (TDS > 1750){
        if (TDS > 1750 && TDS < 2000){
            tds_tinggi = (float)((TDS-1750)/(2000-1750));
        }
        else if (TDS >= 70){
            tds_tinggi = 1;
        }
        cout<<"TDS Tinggi =\t"<<tds_tinggi<<endl;
    }
    }

    //menghitung min
    float min(float x, float y, float z) {
		if (x<=y && x<=z) {
			return x;
			}
		else if (y <= x && y <= z){
            return y;
            }
		else {
			return z;
		}
	}

	//menghitung max
	float max(float w, float x, float y, float z) {
		if ((w>x) && (w>y) && (w>z)){
            return w;
		}
		else if ((x>w) && (x>y) && (x>z)){
            return x;
		}
		else if ((y>w) && (y>z) && (y>x)){
            return y;
		}
		else return z;
	}

	//menghitung array dari max
	float max_array(float x[], int n) {
		float max=0;
		for (int i = 0; i<n; i++) {
			if (x[i] > max) {
				max = x[i];
			}
		}
		return max;
	}

	// aturan yang telah di tetapkan
	void aturan (){
	int i=0, j=0, k=0;

	//peraturan 1
	if (warna_jernih !=0 && tds_rendah !=0 && ph_asam !=0) {
		tercemar_ringan[j] = min(warna_jernih, tds_rendah, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 1 --> Nilai Keanggotaan Tercemar Ringan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 2
	if (warna_jernih !=0 && tds_rendah !=0 && ph_normal !=0) {
		normal[i] = min(warna_jernih, tds_rendah, ph_normal);
		printf("=====================================================\n");
		printf ("|Rules 2 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 3
	if (warna_jernih !=0 && tds_rendah !=0 && ph_basa !=0) {
        normal[i] = min(warna_jernih, tds_rendah, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 3 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 4
	if (warna_jernih !=0 && tds_sedang !=0 && ph_asam !=0) {
		tercemar_ringan[j] = min(warna_jernih, tds_sedang, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 4 --> Nilai Keanggotaan Tercemar Ringan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 5
	if (warna_jernih !=0 && tds_sedang !=0 && ph_normal !=0) {
		normal[i] = min(warna_jernih, tds_sedang, ph_normal);
		printf("=====================================================\n");
		printf ("|Rules 5 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 6
	if (warna_jernih !=0 && tds_sedang !=0 && ph_basa !=0) {
		normal[i] = min(warna_jernih, tds_sedang, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 6 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 7
	if (warna_jernih !=0 && tds_tinggi !=0 && ph_asam !=0) {
		tercemar_ringan[j] = min(warna_jernih, tds_tinggi, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 7 --> Nilai Keanggotaan Tercemar Ringan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 8
	if (warna_jernih !=0 && tds_tinggi !=0 && ph_normal !=0) {
		normal[i] = min(warna_jernih, tds_tinggi, ph_normal);
		printf("=====================================================\n");
		printf ("|Rules 8 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 9
	if (warna_jernih !=0 && tds_tinggi !=0 && ph_basa !=0) {
		normal[i] = min(warna_jernih, tds_tinggi, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 9 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 10
	if (warna_sedang !=0 && tds_rendah !=0 && ph_asam !=0) {
		tercemar_ringan[j] = min(warna_sedang, tds_rendah, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 10 --> Nilai Keanggotaan Tercemar RIngan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 11
	if (warna_sedang !=0 && tds_rendah !=0 && ph_normal !=0) {
		normal[i] = min(warna_sedang, tds_rendah, ph_normal);
		printf("=====================================================\n");
		printf ("|Rules 11 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 12
	if (warna_sedang !=0 && tds_rendah !=0 && ph_basa !=0) {
        normal[i] = min(warna_sedang, tds_rendah, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 12 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 13
	if (warna_sedang !=0 && tds_sedang !=0 && ph_asam !=0) {
		tercemar_ringan[j] = min(warna_sedang, tds_sedang, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 13 --> Nilai Keanggotaan Tercemar RIngan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 14
	if (warna_sedang !=0 && tds_sedang !=0 && ph_normal !=0) {
		normal[i] = min(warna_sedang, tds_sedang, ph_normal);
		printf("=====================================================\n");
		printf ("|Rules 14 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 15
	if (warna_sedang !=0 && tds_sedang !=0 && ph_basa !=0) {
		normal[i] = min(warna_sedang, tds_sedang, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 15 --> Nilai Keanggotaan Normal %.2f|\n", normal[i]);
		printf("=====================================================\n");
		i++;
	}

	//peraturan 16
	if (warna_sedang !=0 && tds_tinggi !=0 && ph_asam !=0) {
		tercemar_berat[k] = min(warna_sedang, tds_tinggi, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 7 --> Nilai Keanggotaan Tercemar Berat %.2f|\n", tercemar_berat[k]);
		printf("=====================================================\n");
		k++;
	}

	//peraturan 17
	if (warna_sedang !=0 && tds_tinggi !=0 && ph_normal !=0) {
		tercemar_ringan[j] = min(warna_sedang, tds_tinggi, ph_normal);
		printf("=====================================================\n");
		printf ("|Rules 8 --> Nilai Keanggotaan Tercemar Ringan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 18
	if (warna_sedang !=0 && tds_tinggi !=0 && ph_basa !=0) {
		tercemar_ringan[j] = min(warna_sedang, tds_tinggi, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 18 --> Nilai Keanggotaan Tercemar Ringan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 19
	if (warna_kuning !=0 && tds_rendah !=0 && ph_asam !=0) {
		tercemar_berat[k] = min(warna_kuning, tds_rendah, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 19 --> Nilai Keanggotaan Tercemar Berat %.2f|\n", tercemar_berat[k]);
		printf("=====================================================\n");
		k++;
	}

	//peraturan 20
	if (warna_kuning !=0 && tds_rendah !=0 && ph_normal !=0) {
		tercemar_ringan[j] = min(warna_kuning, tds_rendah, ph_normal);
		printf("=====================================================\n");
		printf ("|Rules 20 --> Nilai Keanggotaan Tercemar Ringan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 21
	if (warna_kuning !=0 && tds_rendah !=0 && ph_basa !=0) {
        tercemar_ringan[j] = min(warna_kuning, tds_rendah, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 21 --> Nilai Keanggotaan Tercemar Ringan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 22
	if (warna_kuning !=0 && tds_sedang !=0 && ph_asam !=0) {
		tercemar_berat[k] = min(warna_kuning, tds_sedang, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 22 --> Nilai Keanggotaan Tercemar Berat %.2f|\n", tercemar_berat[k]);
		printf("=====================================================\n");
		k++;
	}

	//peraturan 23
	if (warna_kuning !=0 && tds_sedang !=0 && ph_normal !=0) {
		tercemar_ringan[j] = min(warna_kuning, tds_sedang, ph_normal);
		printf("=====================================================\n");
		printf ("|Rules 23 --> Nilai Keanggotaan Tercemar Ringan %.2f|\n", tercemar_ringan[j]);
		printf("=====================================================\n");
		j++;
	}

	//peraturan 24
	if (warna_kuning !=0 && tds_sedang !=0 && ph_basa !=0) {
		tercemar_berat[k] = min(warna_kuning, tds_sedang, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 24 --> Nilai Keanggotaan Tercemar Berat %.2f|\n", tercemar_berat[k]);
		printf("=====================================================\n");
		k++;
	}

	//peraturan 25
	if (warna_kuning !=0 && tds_tinggi !=0 && ph_asam !=0) {
		tercemar_berat[k] = min(warna_kuning, tds_tinggi, ph_asam);
		printf("=====================================================\n");
		printf ("|Rules 25 --> Nilai Keanggotaan Tercemar Berat %.2f|\n", tercemar_berat[k]);
		printf("=====================================================\n");
		k++;
	}

	//peraturan 26
	if (warna_kuning !=0 && tds_tinggi !=0 && ph_normal !=0) {
		tercemar_berat[k] = min(warna_kuning, tds_tinggi, ph_normal);
		printf("=====================================================\n");
		printf("|Rules 26 --> Nilai Keanggotaan Tercemar Berat %.2f| \n", tercemar_berat[k]);
		printf("=====================================================\n");
		k++;
	}

	//peraturan 27
	if (warna_kuning !=0 && tds_tinggi !=0 && ph_basa !=0) {
		tercemar_berat[k] = min(warna_kuning, tds_tinggi, ph_basa);
		printf("=====================================================\n");
		printf ("|Rules 27 --> Nilai Keanggotaan Tercemar Berat %.2f|\n", tercemar_berat[k]);
		printf("=====================================================\n");
		k++;
	}

    printf("=============== Hasil Akhir Inferensi ===============\n");

    if (i==0) {
		hasil_normal = 0;
	}

	else {
		hasil_normal = max_array(normal, i);
		printf("\t Nilai Keanggotaan Normal = %.2f \n", hasil_normal);
	}

	if (j==0) {
		hasil_tercemar_ringan = 0;
	}

	else {
		hasil_tercemar_ringan = max_array(tercemar_ringan, j);
		printf("\t Nilai Keanggotaan Tercemar Ringan = %.2f \n", hasil_tercemar_ringan);
	}

	if (k==0) {
		hasil_tercemar_berat = 0;
	}

	else {
		hasil_tercemar_berat = max_array(tercemar_berat, k);
		printf("\t Nilai Keanggotaan Tercemar Berat =  %.2f \n", hasil_tercemar_berat);
	}
    printf("=====================================================\n");
	}

	float valNKnormal(float x) {
		if (x>0 && x<=9) return 1;
		else {
			if ((x < 12) && (x > 9)) return (float) ((12-x)/3);
				else {
                        if ((x > 12) && (x < 0))
                    return 0;}
			}
		}

	float valNKringan(float x) {
		if (x <= 30 && x >= 12) return 1;
		else {
			if ((x > 9) && (x < 12)) return (float) ((x -9)/3);
			else {
				if ((x > 30) && (x < 32)) return (float) ((32-x)/2);
				else return 0;
			}
		}
	}

	float valNKberat(float x) {
		if (x < 27) return 0;
			else {
			if ((x > 30) && (x < 50)) return (float)((x-27)/23);
				else return 1;
			}
		}

	void defuzz_centroid(int sampel) {
		float min_output=0, max_output=60;
		float x=0, t=(max_output - min_output) / sampel;
		float pengali[100];
		float valnormal, valberat, valringan;
		float crisp_val = 0;
		float sumX = 0;
		int i;

	for (i=0; i<sampel; i++) {
		x=x+t;
		valnormal = valNKnormal(x);
		valringan = valNKringan(x);
		valberat = valNKberat(x);

		if (valnormal > hasil_normal){
			valnormal = hasil_normal;
		}

        if (valringan > hasil_tercemar_ringan){
			valringan = hasil_tercemar_ringan;
        }

		if (valberat > hasil_tercemar_berat){
		valberat= hasil_tercemar_berat;
        }

		if (valnormal>=valringan && valnormal>=valberat){
			pengali[i] = valnormal;
		}

        else if (valringan>=valnormal && valringan>=valberat){
           pengali[i] = valringan;
       }

        else {
            pengali[i]= valberat;
		}

		crisp_val = crisp_val+(x*pengali[i]);
		sumX = sumX + pengali[i];
	}

    crispOutput = crisp_val / sumX;
    printf("Nilai Kelayakan    = %.2f \n" , crispOutput);
	}
};

int main(){
    float ph;
    float tds;
    float warna;
    int titik;
    air test;
    char u;
    ulang:
    printf("\t\t\t========================================== \n");
    printf("\t\t\t====== PROGRAM PENENTU KUALITAS AIR ====== \n");
    printf("\t\t\t======   MENGGUNAKAN LOGIKA FUZZY   ====== \n");
    printf("\t\t\t========================================== \n\n");
    cout<<"Masukkan nilai PH: ";
    cin>>ph;
    cout<<"Masukkan nilai TDS: ";
    cin>>tds;
    cout<<"Masukkan nilai Warna: ";
    cin>>warna;
    printf("\t\t\t=========== PROSES FUZZIFIKASI =========== \n");
    printf("============== Hasil Akhir Fuzzifikasi ==============\n");
    test.anggota_ph(ph);
    test.anggota_tds(tds);
    test.anggota_warna(warna);
    printf("=====================================================\n");
    printf("\t\t\t============ PROSES INFERENSI ============ \n");
    test.aturan();
    printf("=====================================================\n");
    printf("\t\t\t========== PROSES DEFUZZIFIKASI ========== \n");
    cout<<"Masukkan Jumlah Sampel = ";
    cin>>titik;
    printf("============= Hasil Akhir Defuzzifikasi =============\n");
    test.defuzz_centroid(titik);
    printf("=====================================================\n");
    cout<<" Lakukan Prediksi Fuzzy kembali (y/t) :";
    cin>>u;
    if ((u == 'Y')||(u=='y'))goto ulang;
    system("pause");
    return 0;
    }
