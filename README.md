# Pendata-BMI
This source code was made by Ferdinand Daniel, Muhammad Marchell Erniza Putra, Nathaniel Huang

# Deskripsi program
Program ini merupakan program yang mengambil input berupa nama, tinggi, dan berat yang akan disimpan pada file lokal.
Terdapat 4 function pada program ini yaitu :
1. Input data
2. Search data
3. Show data
4. Delete data

# Deskripsi function
1. Input data
    Function ini berfungsi untuk mengambil input dari user untuk disimpan pada file lokal.
    - Alur :
      Program mengambil input dari user berupa nama, tinggi, dan berat. 
      Data nama akan disimpan pada linked-list, sedangkan tinggi dan berat akan diubah ke BMI untuk disimpan pada array,
      Program akan membuat file notepad lokal untuk menyimpan data linked-list dan array tersebut.
    
3. Search data
    Function ini berfungsi untuk mencari data pada database sesuai input user.
    - Alur :
      Program memiliki 2 jenis pencarian yaitu secara nama atau BMI. 
      Pada jenis nama user akan menginput nama yang dicari, sedangkan pada jenis BMI user akan menginput BMI yang dicari.
      Program akan melakukan fungsi search dengan mengecek kesamaan data yang ada dengan input user dan mengoutput nama dan BMI yang dicari
      Program juga akan menambahkan keadaan tubuh dan kesehatan untuk data yang dioutput.
    
5. Show data
    Function ini berfungsi untuk menunjukan data pada database sesuai dengan urutan yang diinginkan user.
    - Alur :
      Program memiliki 6 jenis pengurutan yaitu waktu, nama, dan BMI secara ascending maupun descending.
      Program mengambil input dari user berupa jenis pengurutan yang diinginkan.
      Program akan mengurutkan data tersebut sesuai dengan pilihan user lalu ditampilkan pada layar.
    
7. Delete data
    Function ini berfungsi untuk mendelete data pada database.
    - Alur :
      Program membuka dan mengambil data pada database kedalam sistem lalu ditampilkan. (Jika data kosong maka akan langsung berakhir)
      Program akan meminta input dari user berupa nama dari data yang ingin dihapus.
      Program akan melakukan search data untuk mencari data yang sama lalu dihapus pada data sistem.
      Data sistem tersebut akan ditulis ulang pada database.
    
    
