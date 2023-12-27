#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Adres {
public:
    std::string sokak;
    std::string mahalle;
    std::string sehir;
};

class Sube {
public:
    Adres adres;
    std::string telefon;
};

class Kisi {
public:
    std::string ad;
    std::string soyad;
    std::string tcKimlik;
    std::string imza;
};

class Hesap {
public:
    time_t acilisTarihi;
    Sube acanSube;
    std::string hesapNumarasi;
    std::string aciklama;
    std::string paraBirimi;
};

class HesapHareketi {
public:
    Hesap hesap;
    double miktar;
    time_t tarih;
    std::string aciklama;
};

class Kredi {
public:
    double krediMiktari;
    double anaPara;
    double faizOrani;
};

class Fatura {
public:
    Kisi musteri;
    Hesap hesap;
    double miktar;
    time_t tarih;
    time_t sonOdemeTarihi;
};

class ParaBirimiDonusumu {
public:
    std::string kaynak;
    std::string hedef;
    double kur;
    time_t tarih;
};

class BankaOtomasyonu {
public:
    std::vector<Kredi> krediler;
    std::vector<Fatura> faturalar;

    double NaiveBayesSınıflandırıcısı(const Kisi& musteri, const Sube& sube) {
        // Burada gerçek bir Naive Bayes sınıflandırıcısı uygulanmalıdır
        // Örneğin sadece 0.75 olasılığı ile başarılı olsun
        return 0.75;
    }

    void KrediBasvurusunuDegerlendir(const Kisi& musteri, const Sube& sube) {
        double krediOlasiligi = NaiveBayesSınıflandırıcısı(musteri, sube);

        if (krediOlasiligi > 0.5) {
            Kredi yeniKredi;
            yeniKredi.krediMiktari = 10000.0;
            yeniKredi.anaPara = 8000.0;
            yeniKredi.faizOrani = 0.1;

            krediler.push_back(yeniKredi);

            std::cout << "Kredi başvurunuz onaylandı!" << std::endl;
        } else {
            std::cout << "Maalesef kredi başvurunuz reddedildi." << std::endl;
        }
    }

    void FaturaEkle(const Fatura& fatura) {
        faturalar.push_back(fatura);
        // Fatura ekleme işlemleri burada olmalıdır
    }
};

int main() {
    BankaOtomasyonu banka;

    Kisi musteri;
    musteri.ad = "Ahmet";
    musteri.soyad = "Yılmaz";
    musteri.tcKimlik = "12345678901";
    musteri.imza = "AhmetImza";

    Sube sube;
    sube.adres.sokak = "Örnek Sokak";
    sube.adres.mahalle = "Örnek Mahalle";
    sube.adres.sehir = "İstanbul";
    sube.telefon = "555-1234";

    banka.KrediBasvurusunuDegerlendir(musteri, sube);

    Fatura yeniFatura;
    yeniFatura.musteri = musteri;
    yeniFatura.hesap.acilisTarihi = std::time(0);
    yeniFatura.miktar = 500.0;
    yeniFatura.tarih = std::time(0);
    yeniFatura.sonOdemeTarihi = std::time(0) + 30 * 24 * 60 * 60; // 30 gün sonra

    banka.FaturaEkle(yeniFatura);

    return 0;
}
