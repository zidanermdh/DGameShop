#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct User{
    char username[50];
    char nama[50];
    char password[50];
    char email[100];
    char feedback[50];
    int saldo;
    int developer;
    int no_telp;
} data_user;

struct Game{
    char judul[50];
    char genre[50];
    char platform[50];
    char pengembang[50];
    char tanggalRilis[50];
    int harga;
    float rating;
} game;

FILE *fuser;
FILE *fadmin;
FILE *fdeveloper;
FILE *fgame;
FILE *ffeedback;
FILE *fpendapatan;

int main(){
    MenuLogin();
    return 0;
}

void MenuLogin(){
    int pilihan;
    while (1) {
        system("cls");
        printf("\n=== SELAMAT DATANG DI DGAMESHOP ===\n");
        printf("1. Login Admin\n");
        printf("2. Login User\n");
        printf("3. Login Developer\n");
        printf("4. Registrasi User\n");
        printf("5. Logout\n");
        printf("Silahkan input pilihan anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
            LoginAdmin();
            break;

            case 2:
            LoginUser();
            break;

            case 3:
            LoginDeveloper();
            break;

            case 4:
            RegistrasiUser();
            break;

            case 5:
            printf("Terimakasih Telah Menggunakan DGameShop");
            exit(0);
            break;
    
            default:
            printf("Pilihan tidak valid! Silahkan coba lagi.\n");
            system("pause");
        }    
    }    
}


void LoginAdmin(){
    char username[50], password[50];
    system("cls");
    int i = 0;

    printf("=== Login Admin DGameShop\n");
    while (i < 3) {
        printf("\nMasukan Username: ");
        scanf("%s", &username);
        printf("\nMasukan Password: ");
        scanf("%s", &password);
        if (strcmp(username, "Admin") == 0 && strcmp (password, "Admin123") == 0) {
            printf("Login Berhasil...\n");
            printf("Selamat Datang Admin\n");
            getchar();
            system("pause");
            MenuAdmin(1);
            break;
        } 
        else {
            printf("Username atau Password salah!\n");
            i++;
        }
        if (i < 3) {
            printf("Klik enter untuk ke halaman selanjutnya...\n");
            getchar();
        }
        else {
            printf("Mohon maaf, batas percobaan login telah habis, silahkan coba lagi nanti...");
            system("pause");
            MenuLogin();
        }   

    }  

}

void LoginUser(){
    struct User;
    FILE *fuser;
    char username[50], pw[50];
    int percobaan = 0, berhasil = 0;

    system("cls");
    fuser = fopen("AkunUser.dat", "rb");
    if (fuser == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    printf("=== LOGIN USER ===\n");

    while (percobaan < 3 && !berhasil) {
        getchar();
        printf("Masukan Username: ");
        gets(username);
        printf("Masukan Password: ");
        gets(pw);

        rewind(fuser);
        while (fread(&data_user, sizeof(data_user), 1, fuser) ==1) {
            if (strcmp(username, data_user.username) == 0 && strcmp(pw, data_user.password) == 0) {
                printf("== LOGIN BERHASIL ==\n");
                printf("== SELAMAT DATANG GAMERS ==\n");
                berhasil = 1;
                fclose(fuser);
                system("pause");
                MenuUser();
                return;
            }
            
        }
        percobaan++;
        if (percobaan < 3) {    
            printf("Username atau Password salah! Silahkan coba lagi.\n");
            printf("Percobaan ke-%d dari 3\n", percobaan);
            system("pause");
        } else {
            printf("Mohon maaf, batas percobaan login telah habis, silahkan coba lagi nanti...\n");
            fclose(fuser);
            system("pause");
            MenuLogin();
        }
        
    }
      
}

void LoginDeveloper(){
    char username[50], pw[50];
    int percobaan = 0, berhasil = 0;

    system("cls");
    fuser = fopen("AkunUser.dat", "rb");
    if (fuser == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    printf("=== LOGIN DEVELOPER ===\n");

    while (percobaan < 3 && !berhasil) {
        getchar();
        printf("Masukan Username: ");
        gets(username);
        printf("Masukan Password: ");
        gets(pw);

        rewind(fuser);
        while (fread(&data_user, sizeof(data_user), 1, fuser) ==1) {
            if (strcmp(username, data_user.username) == 0 && strcmp(pw, data_user.password) == 0 && data_user.developer == 1) {
                printf("== LOGIN BERHASIL ==\n");
                printf("== SELAMAT DATANG DEVELOPER ==\n");
                berhasil = 1;
                fclose(fuser);
                system("pause");
                MenuDeveloper();
                return;
            }
            
        }
        percobaan++;
        if (percobaan < 3) {
            printf("Username atau Password salah! Silahkan coba lagi.\n");
            printf("Percobaan ke-%d dari 3\n", percobaan);
            system("pause");
        } else {
            printf("Mohon maaf, batas percobaan login telah habis, silahkan coba lagi nanti...\n");
            fclose(fuser);
            system("pause");
            MenuLogin();
        }
        
    }
      
}

void RegistrasiUser(){
    system("cls");
    fuser = fopen("AkunUser.dat", "ab");

    getchar();
    printf("=== REGISTRASI USER ===\n");
    printf("\nusername: ");
    gets(data_user.username);
    printf("\npassword: ");
    gets(data_user.password);

    data_user.developer = 0;

    fwrite(&data_user, sizeof(data_user), 1, fuser);
    fclose(fuser);

    printf("REGISTRASI BERHASIL...\n");
    system("pause");
    LoginUser();
}

void MenuAdmin(){
    int pilihan;
    while (1) {
        system("cls");
        printf("== SELAMAT DATANG DI MENU ADMIN ==\n");
        printf("1. List Akun User\n");
        printf("2. Kumulatif Pendapatan\n");
        printf("3. Riwayat Pembelian\n");
        printf("4. Logout\n");
        printf("Silahkan input pilihan anda: \n");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
            ListAkunUser();
            break;
            
            case 2:
            KumulatifPendapatan();
            break;

            case 3:
            RiwayatPembelian();
            break;

            case 4:
            printf("Terimakasih Telah Menggunakan DGameShop");
            exit(0);
            break;

            default:
            printf("Pilihan tidak valid!, coba lagi.\n");
            system("pause");
            break;
        }

    }

}
void ListAkunUser(){

}
void KumulatifPendapatan(){

}
void RiwayatPembelian(){

}
void MenuUser(){
    int pilihan;
    while (1) {
        system("cls");
        printf("== SELAMAT DATANG DI MENU USER ==\n");
        printf("1. Home Page\n");
        printf("2. Profile User\n");
        printf("3. Registrasi Developer\n");
        printf("4. Logout\n");
        printf("Silahkan input pilihan anda :");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
            HomePage();
            break;
            
            case 2:
            ProfileUser();
            break;

            case 3:
            RegistrasiDeveloper();
            break;

            case 4:
            printf("Terimakasih telah menggunakan DGameShop!\n");
            exit(0);
            break;

            default:
            printf("Pilihan tidak valid!, silahkan coba lagi.");
            system("pause");
            break;
        }

    }
    
}

void HomePage(){
    int pilihan;
    while (1) {
        system("cls");
        printf("== Selamat Datang di Home Page DGameShop!\n");
        printf("1. Store Page\n");
        printf("2. Wallet\n");
        printf("3. Kembali\n");
        printf("Silahkan input pilihan anda :");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
            StorePage();
            break;

            case 2:
            Wallet();
            break;

            case 3:
            MenuUser();
            break;
        
            default:
            printf("Pilihan tidak valid!, silahkan coba lagi");
            system("pause");
            break;
        }

    }
    
}

void StorePage(){

}
void Searching(){
  
}
void GamePage(){

}
void BeliGame(){

}
void FeedbackGame(){

}
void Wallet(){

}
void ProfileUser(){

}
void RegistrasiDeveloper(){
    system("cls");
    fuser = fopen("AkunUser.dat", "ab");

    getchar();
    printf("=== REGISTRASI DEVELOPER ===\n");
    printf("\nusername: ");
    gets(data_user.username);
    printf("\npassword: ");
    gets(data_user.password);
    printf("\nnama: ");
    gets(data_user.nama);
    printf("\nemail :");
    gets(data_user.email);
    printf("\nnomer telepon: ");
    scanf("%d", &data_user.no_telp);
    getchar();
    printf("\nnomer rekening: ");
    scanf("%d", &data_user.saldo);
    getchar();

    data_user.developer = 1;

    fwrite(&data_user, sizeof(data_user), 1, fuser);
    fclose(fuser);

    printf("REGISTRASI BERHASIL...\n");
    system("pause");
    LoginDeveloper();
}

void MenuDeveloper(){
    int pilihan;
    while (1) {
        system("cls");
        printf("=== SELAMAT DATANG DI MENU DEVELOPER ===\n");
        printf("1. Tambah Game\n");
        printf("2. Update Game\n");
        printf("3. Lihat Feedback\n");
        printf("4. Logout\n");
        printf("Silahkan Input Pilihan Anda :\n");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
            TambahGame();
            break;
            
            case 2:
            UpdateGame();
            break;
        
            case 3:
            LihatFeedback();
            break;
        
            case 4:
            printf("Terimakasih Telah Menggunakan DGameShop!\n");
            exit(0);
            break;

            default:
            printf("Pilihan anda tidak valid!, silahkan coba lagi\n");
            system("pause");
            break;
        }

    }
    
}

void TambahGame(){
    fgame = fopen("games.dat", "ab");
    if (fgame == NULL) {
        printf("Gagal membuka file!");
        return;
    }

    system("cls");
    printf("=== TAMBAH GAME ==="); 
    printf("Masukan Judul Game :\n");
    gets(game.judul);
    printf("Masukan Genre Game :\n");
    gets(game.genre);
    printf("Masukan Platform Game :\n");
    gets(game.platform);
    printf("Masukan Pengembang Game :\n");
    gets(game.pengembang);
    printf("Masukan Tanggal Rilis Game :\n");
    gets(game.tanggalRilis);
    printf("Masukan Harga Game :\n");
    scanf("%d", &game.harga);
    printf("Masukan Rating Game :\n");
    scanf("%f", &game.rating);
    getchar();

    fwrite(&game, sizeof(game), 1, fgame);
    fclose(fgame);

    printf("Game berhasil ditambahkan!\n");
    system("pause");
    MenuDeveloper();

}
void UpdateGame(){
    fgame = fopen("games.dat", "rb+");
    if (fgame == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    system("cls");
    printf("=== UPDATE GAME ===\n");
    
    printf("Masukan Judul Game yang ingin diupdate:\n");
    char judul[50]; 
    gets(judul);
    rewind(fgame);

    int ditemukan = 0;
    while (fread(&game, sizeof(game), 1, fgame) == 1) {
        if (strcmp(game.judul, judul) == 0) {
            printf("Masukan Genre Game Baru:\n");
            gets(game.genre);
            printf("Masukan Platform Game Baru:\n");
            gets(game.platform);
            printf("Masukan Pengembang Game Baru:\n");
            gets(game.pengembang);
            printf("Masukan Tanggal Rilis Game Baru:\n");
            gets(game.tanggalRilis);
            printf("Masukan Harga Game Baru:\n");
            scanf("%d", &game.harga);
            printf("Masukan Rating Game Baru:\n");
            scanf("%f", &game.rating);
            getchar();

            fseek(fgame, -sizeof(game), SEEK_CUR);
            fwrite(&game, sizeof(game), 1, fgame);
            ditemukan = 1;
            printf("Game berhasil diupdate!\n");
            break;
        }
    }
    fclose(fgame);

    if (!ditemukan) {
        printf("Game dengan judul '%s' tidak ditemukan!\n", judul);
    }
    system("pause");
    MenuDeveloper();
}

void LihatFeedback(){
    ffeedback = fopen("feedback.dat", "rb");
    if (ffeedback == NULL) {
        printf("Gagal membuka file feedback!\n");
        return;
    }

    system("cls");
    printf("=== LIHAT FEEDBACK ===\n");
    int ada = 0;
    while (fread(&data_user, sizeof(data_user), 1, ffeedback) == 1) {
        if (data_user.feedback[0] != '\0') {
            printf("Username: %s\n", data_user.username);
            printf("Feedback: %s\n", data_user.feedback);
            printf("-------------------------\n");
            ada = 1;
        }
    }
    if (!ada) {
        printf("Tidak ada feedback yang tersedia.\n");
    }
    fclose(ffeedback);
    system("pause");
    MenuDeveloper();
}
