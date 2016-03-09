cd ../; make; cd -;

echo "[Nm] Test"

echo "[my_Nm] Test 32 Bits"
../my_nm bin_32 > my_nm32
echo "[Nm] Test 32 Bits"
nm bin_32 > nm32

echo "[my_Nm] Test 64 Bits"
../my_nm bin_64 > my_nm64
echo "[Nm] Test 64 Bits"
nm bin_64 > nm64

echo "[my_Nm] Test Malloc"
../my_nm libmy_malloc_.so > my_nmmalloc
echo "[Nm] Test Malloc"
nm libmy_malloc_.so > nmmalloc

echo "[my_Nm] Test Exe"
../my_nm test.exe > my_nmexe
echo "[Nm] Test Exe"
nm test.exe > nmexe

echo "[my_Nm] Test Tar"
../my_nm test.tar.gz > my_nmtar
echo "[Nm] Test Tar"
nm test.tar.gz > nmtar

echo "[my_Nm] Test .o"
../my_nm test.o > my_nmo
echo "[Nm] Test .o"
nm test.o > nmo

echo "[Objdump] Test"
echo "[my_Objdump] Test 32 Bits"
../my_objdump bin_32 > my_objdump32
echo "[Objdump] Test 32 Bits"
objdump -sf bin_32 > objdump32

echo "[my_Objdump] Test 64 Bits"
../my_objdump bin_64 > my_objdump64
echo "[Objdump] Test 64 Bits"
objdump -sf bin_64 > objdump64

echo "[my_Objdump] Test Malloc"
../my_objdump libmy_malloc_.so > my_objdumpmalloc
echo "[Objdump] Test Malloc"
objdump -sf libmy_malloc_.so > objdumpmalloc

echo "[my_Objdump] Test Exe"
../my_objdump test.exe > my_objdumpexe
echo "[Objdump] Test Exe"
objdump -sf test.exe > objdumpexe

echo "[my_Objdump] Test Tar"
../my_objdump test.tar.gz > my_objdumptar
echo "[Objdump] Test Tar"
objdump -sf test.tar.gz > objdumptar

echo "[my_Objdump] Test .o"
../my_objdump test.o > my_objdumpo
echo "[Objdump] Test .o"
objdump -sf test.o > objdumpo

echo "Start Diff"

echo "[Nm] 32 Bits"
diff --suppress-common-lines my_nm32 nm32
echo "[Nm] 64 Bits"
diff --suppress-common-lines my_nm64 nm64
echo "[Nm] Malloc"
diff --suppress-common-lines my_nmmalloc nmmalloc
echo "[Nm] Exe"
diff --suppress-common-lines my_nmexe nmexe
echo "[Nm] Tar"
diff --suppress-common-lines my_nmtar nmtar
echo "[Nm] .o"
diff --suppress-common-lines my_nmo nmo

echo "[Objdump] 32 Bits"
diff --suppress-common-lines my_objdump32 objdump32
echo "[Objdump] 64 Bits"
diff --suppress-common-lines my_objdump64 objdump64
echo "[Objdump] Malloc"
diff --suppress-common-lines my_objdumpmalloc objdumpmalloc
echo "[Objdump] Exe"
diff --suppress-common-lines my_objdumpexe objdumpexe
echo "[Objdump] Tar"
diff --suppress-common-lines my_objdumptar objdumptar
echo "[Objdump] .o"
diff --suppress-common-lines my_objdumpo objdumpo

echo "End Diff"

cd ../; make fclean; cd -;
