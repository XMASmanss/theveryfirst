#include <iostream>
using namespace std;

int main() {
    int tp1 = 0, tp2 = 1;   
    int ngl, gio;
    std::cout << "Số nguyên liệu: ";
    std::cin >> ngl;
    std::cout << "Số giờ: ";
    std::cin >> gio;
    
    const int nguyenlieu = ngl, hour = gio;
    
    
    int nl = ngl, h = gio;
    struct {
        int ngl, gio, ln;
    } sp1, sp2;
    
    int ngl1, ngl2, gio1, gio2, ln1, ln2;
    std::cout << "Sô nguyên liệu dùng cho sản phẩm 1: ";
    std::cin >> ngl1;
    std::cout << "Sô nguyên liệu dùng cho sản phẩm 2: ";    
    std::cin >> ngl2;    
    std::cout << "Sô giờ cần cho sản phẩm 1: ";
    std::cin >> gio1;
    std::cout << "Sô giờ cần cho sản phẩm 2: ";
    std::cin >> gio2;
    std::cout << "Lợi nhuận từ sản phẩm 1: ";
    std::cin >> ln1;
    std::cout << "Lợi nhuận từ sản phẩm 2: ";
    std::cin >> ln2;    
    sp1.ngl = ngl1;
    sp1.gio = gio1;
    sp1.ln = ln1;
    
    int loinhuantrc;
    int loinhuansau;
    int tnl2;
    int th2;

    sp2.ngl = ngl2;
    sp2.gio = gio2;
    sp2.ln = ln2;
    
    tnl2 = sp2.ngl*tp2;
    th2 = sp2.gio*tp2;    
    nl = nl - tp2*sp2.ngl;
    h = h - tp2*sp2.gio;
    
    while (nl / tnl2 >= 1 && h / th2 >= 1) {
            tp2 ++;        
            tnl2 = sp2.ngl*tp2;
            th2 = sp2.gio*tp2;
    }

    int tnl1, th1;
    do {
        loinhuantrc = tp1*sp1.ln + tp2*sp2.ln;
        tp2--;
      
        tnl1 = tp1*sp1.ngl;
        th1 = tp1*sp1.gio;
        nl = nguyenlieu - tp2*sp2.ngl - tnl1;
        h = hour - tp2*sp2.gio - th1;
        

        if (nl >= sp1.ngl && h >= sp1.gio) {
            while (nl / sp1.ngl >= 1 && h / sp1.gio >= 1) {
                tp1++;
                tnl1 = tp1*sp1.ngl;
                th1 = tp1*sp1.gio;
                nl = nguyenlieu - tp2*sp2.ngl - tnl1;
                h = hour - tp2*sp2.gio - th1;
            }
        }
        
        loinhuansau = tp1*sp1.ln + tp2*sp2.ln;
    
    } while (loinhuansau>=loinhuantrc);

    if (nl >= sp2.ngl && h >= sp2.gio) {
        tp2++;
    }
    loinhuansau = tp1*sp1.ln + tp2*sp2.ln;
    std::cout << endl << "Số kg loại 1: " << tp1 << endl << "Số kg loại 2: " << tp2 << endl << "Lợi nhuận: " << loinhuansau;
}