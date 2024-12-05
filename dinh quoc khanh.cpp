#include <stdio.h>

int main() {
    int n = 0;
    int mang[100];
    int lua_chon;

    while (1) {
        printf("\nMenu\n");
        printf("1. Nhap so ph?n t? v� gi� tr? cho m?ng\n");
        printf("2. In ra gi� tr? c�c ph?n t? c� trong m?ng\n");
        printf("3. �?m s? lu?ng c�c s? nguy�n t? c� trong m?ng\n");
        printf("4. T�m gi� tr? nh? th? hai trong m?ng\n");
        printf("5. Th�m m?t ph?n t? v�o v? tr� ng?u nhi�n trong m?ng\n");
        printf("6. X�a ph?n t? t?i m?t v? tr� c? th?\n");
        printf("7. S?p x?p m?ng theo th? t? gi?m d?n\n");
        printf("8. T�m ki?m m?t ph?n t? trong m?ng\n");
        printf("9. X�a to�n b? ph?n t? tr�ng l?p v� hi?n th? c�c ph?n t? duy nh?t\n");
        printf("10. �?o ngu?c th? t? c�c ph?n t? trong m?ng\n");
        printf("11.thoat\n");
        printf("L?a ch?n c?a b?n l�: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1: {
                printf("Nh?p s? ph?n t? c?a m?ng (t? 1-100): ");
                scanf("%d", &n);
                if (n <= 0 || n > 100) {
                    printf("S? ph?n t? kh�ng h?p l?!\n");
                    n = 0;
                    break;
                }
                for (int i = 0; i < n; i++) {
                    printf("Nh?p gi� tr? cho mang[%d]: ", i);
                    scanf("%d", &mang[i]);
                }
                break;
            }
            case 2: {
                printf("C�c gi� tr? trong m?ng: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", mang[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                int dem = 0;
                for (int i = 0; i < n; i++) {
                    int so_nt = 1; 
                    if (mang[i] < 2) {
                        so_nt = 0;
                    } else {
                        for (int j = 2; j * j <= mang[i]; j++) {
                            if (mang[i] % j == 0) {
                                so_nt = 0;
                                break;
                            }
                        }
                    }
                    if (so_nt) {
                        dem++;
                    }
                }
                printf("C� %d s? nguy�n t? trong m?ng.\n", dem);
                break;
            }
            case 4: {
                if (n < 2) {
                    printf("M?ng ph?i c� �t nh?t 2 ph?n t? d? t�m gi� tr? nh? th? hai.\n");
                } else {
                    int min1 = mang[0], min2 = __INT_MAX__;
                    for (int i = 1; i < n; i++) {
                        if (mang[i] < min1) {
                            min2 = min1;
                            min1 = mang[i];
                        } else if (mang[i] < min2 && mang[i] != min1) {
                            min2 = mang[i];
                        }
                    }
                    if (min2 == __INT_MAX__) {
                        printf("Kh�ng c� gi� tr? nh? th? hai (c�c ph?n t? d?u gi?ng nhau).\n");
                    } else {
                        printf("Gi� tr? nh? th? hai trong m?ng l�: %d\n", min2);
                    }
                }
                break;
            }
            case 5: {
                if (n == 0) {
                    printf("M?ng r?ng!\n");
                } else {
                    int vitri_them, phantu_moi;
                    printf("B?n mu?n th�m ph?n t? v�o v? tr� n�o (t? 0 d?n %d): ", n);
                    scanf("%d", &vitri_them);
                    if (vitri_them < 0 || vitri_them > n) {
                        printf("V? tr� kh�ng h?p l?!\n");
                        break;
                    }
                    printf("Nh?p gi� tr? ph?n t? m?i: ");
                    scanf("%d", &phantu_moi);
                    for (int i = n; i > vitri_them; i--) {
                        mang[i] = mang[i - 1];
                    }
                    mang[vitri_them] = phantu_moi;
                    n++;
                    printf("M?ng sau khi th�m: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", mang[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 6: {
                if (n == 0) {
                    printf("M?ng r?ng!\n");
                } else {
                    int vitri_xoa;
                    printf("Nh?p v? tr� mu?n x�a (t? 0 d?n %d): ", n - 1);
                    scanf("%d", &vitri_xoa);
                    if (vitri_xoa < 0 || vitri_xoa >= n) {
                        printf("V? tr� kh�ng h?p l?!\n");
                        break;
                    }
                    for (int i = vitri_xoa; i < n - 1; i++) {
                        mang[i] = mang[i + 1];
                    }
                    n--;
                    printf("M?ng sau khi x�a: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", mang[i]);
                    }
                    
                }
                break;
            }
            case 7: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (mang[i] < mang[j]) {
                            int temp = mang[i];
                            mang[i] = mang[j];
                            mang[j] = temp;
                        }
                    }
                }
                printf("M?ng sau khi s?p x?p gi?m d?n: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", mang[i]);
                }
                printf("\n");
                break;
            }
            case 8:{
            	
    int tim_thay = 0;
    int phantu_tim;
    printf("Nhap phan tu ma ban dang tim kiem: ");
    scanf("%d", &phantu_tim); 

    for (int i = 0; i < n; i++) {
        if (mang[i] == phantu_tim) { 
            tim_thay = 1;
            break; 
        }
    }

    if (tim_thay == 1) { 
        printf("Phan tu %d co trong mang.\n", phantu_tim);
    } else {
        printf("%d khong co trong mang.\n", phantu_tim);
    }
    break;
}

       
            case 10: {
                printf("M?ng sau khi d?o ngu?c: ");
                for (int i = 0; i < n / 2; i++) {
                    int temp = mang[i];
                    mang[i] = mang[n - 1 - i];
                    mang[n - 1 - i] = temp;
                }
                for (int i = 0; i < n; i++) {
                    printf("%d ", mang[i]);
                }
                
                break;
            }
            case 11:
            	printf(" thoat khoi chuong trinh");
            	break;
            default:
                printf("L?a ch?n kh�ng h?p l?!\n");
                break;
        }
    }
    return 0;
}
