#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include "Offsets.hpp"
#include <stdio.h>
#include <tchar.h>

using namespace std;

typedef LONG(WINAPI* TNtReadVirtualMemory)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesReaded);
typedef LONG(WINAPI* TNtWriteVirtualMemory)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToWrite, PULONG  NumberOfBytesWritten);
TNtReadVirtualMemory pfnNtReadVirtualMemory = NULL;
TNtWriteVirtualMemory pfnNtWriteVirtualMemory = NULL;
extern TNtReadVirtualMemory pfnNtReadVirtualMemory;
extern TNtWriteVirtualMemory pfnNtWriteVirtualMemory;

int GetCSPID()
{
	int pid;
	DWORD pidDw;
	HWND hWnd = FindWindowA(0, ("Counter-Strike: Global Offensive"));
	if (hWnd != NULL)
	{
		GetWindowThreadProcessId(hWnd, &pidDw);
		pid = (int)pidDw;
		return pid; 
	}
	else {
		pid = 0;
		return pid;
	}
}

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modname)
{
	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry))
		{
			do
			{
				wchar_t WBuf[256];
				mbstowcs(WBuf, modEntry.szModule, 256);
				if (!_wcsicmp(WBuf, modname))
				{
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	CloseHandle(hSnap);
	return modBaseAddr;
}

int main()
{
	// Hook r/w functions from Windows kernel.
	pfnNtReadVirtualMemory = (TNtReadVirtualMemory)GetProcAddress(GetModuleHandle(_T("ntdll.dll")), "NtReadVirtualMemory");
	pfnNtWriteVirtualMemory = (TNtWriteVirtualMemory)GetProcAddress(GetModuleHandle(_T("ntdll.dll")), "NtWriteVirtualMemory");

	int pid = GetCSPID(); 
	printf("[*] pid: %d\n", pid);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	uintptr_t clint = GetModuleBaseAddress(pid, L"client.dll");

	int m_fFlags;
	int goup = 5;
	int godown = 4; 
	while (true)
	{
		ReadProcessMemory(hProcess, (LPCVOID)(clint + hazedumper::signatures::dwLocalPlayer), &dwLocalPlayer, sizeof(uintptr_t), NULL);
		
		while (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{ 
			pfnNtReadVirtualMemory(hProcess, (PVOID)(dwLocalPlayer + hazedumper::netvars::m_fFlags), &m_fFlags, 4, NULL);


			if (m_fFlags == 256)
			{
				
				pfnNtWriteVirtualMemory(hProcess, (PVOID)(clint + hazedumper::signatures::dwForceJump), &godown, 4, NULL);

			}
			else
			{
				pfnNtWriteVirtualMemory(hProcess, (PVOID)(clint + hazedumper::signatures::dwForceJump), &goup, 4, NULL);
			}
		}

	}


}

class xdbiqga {
public:
	bool afjjpxver;
	bool wriledzycfa;
	bool fmrgslkqvyra;
	xdbiqga();
	int reortwcdolvhlcyc(int mspvviexxzukz);

protected:
	double cwfspgilgqvbtk;
	double mkytsmctuhijzhu;
	string jcvczszrnh;
	double kvnjunr;

	void qjlulsdxggoygjd(bool bldrrslubbxqubw);
	void jxemlqiiubpigibi(int kwgnzrvkhd);
	double scwezlbtgbhhkgbcwt();
	void azatbogojauqsmnswgvuvd(string frojxiukznd, int zvmdwqugulgnmpw, int dtunnggcybutos, string xxllk, string pqmrxqmbmh);
	string rlownditeclfhifotz(bool ggmtgvfhcr, int jfghyjfgzzok, string lfkxcrrdyh, string sewjwjyfmvhj, double puzeid, bool pvgxlxdzz, bool wedltzygqjshsfs, bool bnlkrkztdf);
	bool ttdihdciclwfwmmbzdgxlmw(double ehfaapmhehizwuo, double sohel, double ratyddesxqsppt);
	void vldbxeizuehueu(bool zotejvlf, string wdqvdd, string ytymmpnh, double ycwnskwezzol, bool svmzr, bool ajbnuapiwgbglvm, int mvhjpsqwhu, bool efyswfxfdog);

private:
	string utuipnfjlx;
	string nvfvkg;

	void jgjckjuxhgughp(string cabxdape, string qmoynnhtpwc, int eaqyjfg, double ptnye, string wrfmslk, double ywhviygpp);
	double yrghbyzfyafqymfghdxsqrrlu(bool ftjhbjm, string mfxjhiqtt, string sxcuzcghvfh, bool vfjqgmyopkn, int aatsvxqqucrmgq, double bhezq, int qrtupxszbn, string lhfmidhjckceo);
	double bkakryuuilgicugse(int qmajfwcjvqydck, bool bnmkhnrqwqmgxa, bool bksnzvwqnde, int xzobd, int jjcfrddvsxbdher, double rsxigke, double tpksclvxyonpezj);
	double kgblwtfdhbxe(double nvmehkc, bool rbebvixawocnx, string qjgwhuerapyzk, bool opqindhskagof, string wqzjchvzyoyymyn, double tarfmxnymkkx, int qnhhdm, int cetwcdyfvhzvya, double wkmrokvyjso, string peizcivjvvqecgc);
	int ihyvltmjdnrjrsiiraplrftzl(string uukuat, int gvbgqspid, double hkpjxfaakbmqqz, bool avvhju, double kevvnurfw, double hsjzo, string ibfhenbkwqyrz, bool hhmglwccdkgl);
	string gidkdcdvsqfdlk(int shlxmvtbat, double heichjmjfjn, double llyiljiiuoossh, string xbmmbrxjz, bool whalc, double kqukujkaq, int qpcyivakcxxquvc, double fxqcyrbpbymzzaw);
	bool bhkcdarbcjpzfytlgro(bool gzsqi, double zemzpscdjzibyf);
	bool zjlyhwxtinrfhwzjnutoeoi();
	bool ckjundnimhxvz(int ykdupwjcwhgr, string fccfpnbvpziyp, double ytcmmyvewb, string vgxqkcdmkbgjcr);

};


void xdbiqga::jgjckjuxhgughp(string cabxdape, string qmoynnhtpwc, int eaqyjfg, double ptnye, string wrfmslk, double ywhviygpp) {
	string hgiiadkycn = "cfeqangcjaldygvlleotjevxx";
	double ndyfysien = 41459;
	string xezqfmuzj = "ulpwtvlqvpfkhkgssuayshjvpynaxjntwtjcodaltmnkwsxdpctmjcqdmsglrvawjfmutfojordxidp";
	string bayiurqitye = "lonxqzumjtxmkudcubeewb";
	double yfmckem = 6044;
	string qsktkz = "wyhithwxilrxwpyeujgxnklyoqqggvzujddlfkplzqoxfyjnmlpdfpttwauigcwwylxbkwtsiinpoclctxkbetdhkcwyqgl";

}

double xdbiqga::yrghbyzfyafqymfghdxsqrrlu(bool ftjhbjm, string mfxjhiqtt, string sxcuzcghvfh, bool vfjqgmyopkn, int aatsvxqqucrmgq, double bhezq, int qrtupxszbn, string lhfmidhjckceo) {
	bool noeug = true;
	double tqzhwu = 3771;
	bool oyyhuozjefnvb = true;
	string qasjwmcu = "yiqvogwmiukkhozqfjsfifdnmlvtrkphzopnljkgbhrnylscejcgyf";
	int ainiolddatwfl = 3066;
	string yfnlfnhpxbjbjjo = "iztktkiosadtvglpoxstfcswwkgxqpavweelbgznunqjxnfdslghzjsgfewv";
	double gurucwxs = 26681;
	string emvurt = "oghxxdwavidtuao";
	bool cmbjnjgksvdf = true;
	int ollokxpgurbs = 640;
	if (string("iztktkiosadtvglpoxstfcswwkgxqpavweelbgznunqjxnfdslghzjsgfewv") != string("iztktkiosadtvglpoxstfcswwkgxqpavweelbgznunqjxnfdslghzjsgfewv")) {
		int idxtlltsd;
		for (idxtlltsd = 36; idxtlltsd > 0; idxtlltsd--) {
			continue;
		}
	}
	if (string("yiqvogwmiukkhozqfjsfifdnmlvtrkphzopnljkgbhrnylscejcgyf") != string("yiqvogwmiukkhozqfjsfifdnmlvtrkphzopnljkgbhrnylscejcgyf")) {
		int gmcvifr;
		for (gmcvifr = 28; gmcvifr > 0; gmcvifr--) {
			continue;
		}
	}
	if (640 != 640) {
		int rvq;
		for (rvq = 11; rvq > 0; rvq--) {
			continue;
		}
	}
	if (true != true) {
		int rtlazkk;
		for (rtlazkk = 90; rtlazkk > 0; rtlazkk--) {
			continue;
		}
	}
	if (true == true) {
		int pylgawyyt;
		for (pylgawyyt = 4; pylgawyyt > 0; pylgawyyt--) {
			continue;
		}
	}
	return 56911;
}

double xdbiqga::bkakryuuilgicugse(int qmajfwcjvqydck, bool bnmkhnrqwqmgxa, bool bksnzvwqnde, int xzobd, int jjcfrddvsxbdher, double rsxigke, double tpksclvxyonpezj) {
	bool lgmvns = true;
	string jgsysuiqooaxd = "jkovsatqnjtnykflaugbxjhyptnucqh";
	bool pjzogzsulvik = true;
	return 17080;
}

double xdbiqga::kgblwtfdhbxe(double nvmehkc, bool rbebvixawocnx, string qjgwhuerapyzk, bool opqindhskagof, string wqzjchvzyoyymyn, double tarfmxnymkkx, int qnhhdm, int cetwcdyfvhzvya, double wkmrokvyjso, string peizcivjvvqecgc) {
	string luaicpagcjhisf = "fcwhnipspsnfpwifiyrcdajocnirrkvuivvguqllpqyaccr";
	int gboyy = 1360;
	string skmtxaippic = "dsxbtkdvmobhradgkwmanzkcwfrcsqtdvglitwcxfajo";
	bool begkovtcb = false;
	string vaieqorneretgb = "pxpksvqzwwf";
	string tlggnvnkwney = "duepzmnkxztbkrflyihwhictajnykhhafysoyxlcofgadsqcijkdhwhbnkncbbragbtlrxqerrmjalibvkrl";
	return 74525;
}

int xdbiqga::ihyvltmjdnrjrsiiraplrftzl(string uukuat, int gvbgqspid, double hkpjxfaakbmqqz, bool avvhju, double kevvnurfw, double hsjzo, string ibfhenbkwqyrz, bool hhmglwccdkgl) {
	string gcnlbytsmhudyll = "ynoazwdfdvgauesapbraeetadwdumqziuuacksgiuewiwzkplxbhqsprpjqzscza";
	bool efbixjt = false;
	if (string("ynoazwdfdvgauesapbraeetadwdumqziuuacksgiuewiwzkplxbhqsprpjqzscza") != string("ynoazwdfdvgauesapbraeetadwdumqziuuacksgiuewiwzkplxbhqsprpjqzscza")) {
		int xqbj;
		for (xqbj = 50; xqbj > 0; xqbj--) {
			continue;
		}
	}
	if (false == false) {
		int qgf;
		for (qgf = 50; qgf > 0; qgf--) {
			continue;
		}
	}
	if (string("ynoazwdfdvgauesapbraeetadwdumqziuuacksgiuewiwzkplxbhqsprpjqzscza") == string("ynoazwdfdvgauesapbraeetadwdumqziuuacksgiuewiwzkplxbhqsprpjqzscza")) {
		int odqrr;
		for (odqrr = 23; odqrr > 0; odqrr--) {
			continue;
		}
	}
	return 91558;
}

string xdbiqga::gidkdcdvsqfdlk(int shlxmvtbat, double heichjmjfjn, double llyiljiiuoossh, string xbmmbrxjz, bool whalc, double kqukujkaq, int qpcyivakcxxquvc, double fxqcyrbpbymzzaw) {
	bool qmvoomprkrwlqj = true;
	bool lhumzpajfqu = true;
	double ugftx = 35924;
	int obrxymj = 689;
	string khicwfhx = "ozaovwtuayrfftdkkuupdioafuavvwsycaxlpghwlnngfvrqtpnpspfxt";
	int ljerglprwnwhgbe = 328;
	bool uscwguhjyg = true;
	double hqqfdh = 34008;
	bool jhokrgz = false;
	int zyijtr = 525;
	return string("zipwxcwggih");
}

bool xdbiqga::bhkcdarbcjpzfytlgro(bool gzsqi, double zemzpscdjzibyf) {
	double lugcgmnc = 12190;
	bool depyyyenrqlaxaj = true;
	bool eamhwubzpzwi = false;
	if (false != false) {
		int su;
		for (su = 92; su > 0; su--) {
			continue;
		}
	}
	if (12190 != 12190) {
		int udhkfuz;
		for (udhkfuz = 13; udhkfuz > 0; udhkfuz--) {
			continue;
		}
	}
	return false;
}

bool xdbiqga::zjlyhwxtinrfhwzjnutoeoi() {
	int pxokohmn = 1124;
	string qtphtafqwgqy = "cjfkmd";
	int vydoqiaiwyknk = 4288;
	string nblymvr = "bsr";
	if (1124 != 1124) {
		int uxpufv;
		for (uxpufv = 83; uxpufv > 0; uxpufv--) {
			continue;
		}
	}
	if (4288 == 4288) {
		int kpbevqnvz;
		for (kpbevqnvz = 21; kpbevqnvz > 0; kpbevqnvz--) {
			continue;
		}
	}
	if (string("cjfkmd") == string("cjfkmd")) {
		int xtlfatyufy;
		for (xtlfatyufy = 95; xtlfatyufy > 0; xtlfatyufy--) {
			continue;
		}
	}
	if (string("cjfkmd") != string("cjfkmd")) {
		int alrelxfde;
		for (alrelxfde = 5; alrelxfde > 0; alrelxfde--) {
			continue;
		}
	}
	return false;
}

bool xdbiqga::ckjundnimhxvz(int ykdupwjcwhgr, string fccfpnbvpziyp, double ytcmmyvewb, string vgxqkcdmkbgjcr) {
	double mrtpk = 36930;
	string cpdihqanh = "fpdgvzdezfjhxzkwmhniqsmhftdcijtizxewikx";
	if (36930 == 36930) {
		int jjshaze;
		for (jjshaze = 3; jjshaze > 0; jjshaze--) {
			continue;
		}
	}
	return false;
}

void xdbiqga::qjlulsdxggoygjd(bool bldrrslubbxqubw) {
	double ujlwgw = 6894;
	double fwzohfyvmrli = 38716;
	bool lfgfw = false;
	bool aceetbbpjqmnxzd = false;
	if (false == false) {
		int pgfr;
		for (pgfr = 40; pgfr > 0; pgfr--) {
			continue;
		}
	}
	if (6894 == 6894) {
		int dhydgheye;
		for (dhydgheye = 22; dhydgheye > 0; dhydgheye--) {
			continue;
		}
	}

}

void xdbiqga::jxemlqiiubpigibi(int kwgnzrvkhd) {
	bool wightaqxodglrnz = true;
	string qqcgbmeninjwvcq = "luqamuvcjtbmbhbzushitpyzo";
	bool cuiiv = true;
	bool cfadxdfbecxgc = false;
	double cbtdi = 8587;
	string vqiiael = "soihliybwiowgheannpfdtbirghsqidwuiyvrwqcrhpqbanyjwgtsbrpnbi";
	double jomxuqczg = 71179;
	int rkqaochkbysrtni = 2736;
	bool staqkkvfnphhz = true;
	if (8587 == 8587) {
		int dedmgumt;
		for (dedmgumt = 71; dedmgumt > 0; dedmgumt--) {
			continue;
		}
	}
	if (2736 == 2736) {
		int fge;
		for (fge = 34; fge > 0; fge--) {
			continue;
		}
	}
	if (string("luqamuvcjtbmbhbzushitpyzo") == string("luqamuvcjtbmbhbzushitpyzo")) {
		int ehua;
		for (ehua = 41; ehua > 0; ehua--) {
			continue;
		}
	}

}

double xdbiqga::scwezlbtgbhhkgbcwt() {
	string bqbysdfmxwalog = "iopktcehgcmwpatyhklkkmecekaaqyvbmizfvymkczwknxapiuotmvzzzgiydzwahrfdltujqjsrzfdj";
	bool jrrybocvfeqfrlw = false;
	string rcbemw = "olzqhtnx";
	bool mtpyhrrgproo = true;
	int xmolwzljcuedv = 2515;
	string dffql = "fqonvfhflntqfunfoumfy";
	string qkjptrpd = "dduxukyzolblzftvejslbiaqqovnpbjzxafthzqexuyi";
	double walviopkif = 52953;
	string davhfknefaivlbx = "bgxswfyohjsbdvmmjobisuxtlehrezeeexjwhvwbluguqyflmuqnmwymjgpztngqvqfnnqbegabbhmnnukitwuystngwfgg";
	int qidyv = 5246;
	if (2515 != 2515) {
		int qjglnnnszi;
		for (qjglnnnszi = 58; qjglnnnszi > 0; qjglnnnszi--) {
			continue;
		}
	}
	return 49852;
}

void xdbiqga::azatbogojauqsmnswgvuvd(string frojxiukznd, int zvmdwqugulgnmpw, int dtunnggcybutos, string xxllk, string pqmrxqmbmh) {
	double uvefzv = 25586;
	double zklwlukgoztx = 5853;
	double kfwkrsejhkbt = 54808;
	int fpvcjxncnglfu = 1794;
	if (5853 != 5853) {
		int jupehdlnkp;
		for (jupehdlnkp = 24; jupehdlnkp > 0; jupehdlnkp--) {
			continue;
		}
	}
	if (54808 != 54808) {
		int btawpa;
		for (btawpa = 99; btawpa > 0; btawpa--) {
			continue;
		}
	}
	if (54808 == 54808) {
		int mk;
		for (mk = 23; mk > 0; mk--) {
			continue;
		}
	}
	if (54808 != 54808) {
		int dvikbf;
		for (dvikbf = 14; dvikbf > 0; dvikbf--) {
			continue;
		}
	}
	if (25586 != 25586) {
		int ccllgypybz;
		for (ccllgypybz = 58; ccllgypybz > 0; ccllgypybz--) {
			continue;
		}
	}

}

string xdbiqga::rlownditeclfhifotz(bool ggmtgvfhcr, int jfghyjfgzzok, string lfkxcrrdyh, string sewjwjyfmvhj, double puzeid, bool pvgxlxdzz, bool wedltzygqjshsfs, bool bnlkrkztdf) {
	double judxhfmlvwtakl = 38643;
	bool ckpvhrmimup = false;
	double hzsktowtvchmmhu = 273;
	if (false != false) {
		int xmaduo;
		for (xmaduo = 94; xmaduo > 0; xmaduo--) {
			continue;
		}
	}
	if (38643 != 38643) {
		int nzpdid;
		for (nzpdid = 41; nzpdid > 0; nzpdid--) {
			continue;
		}
	}
	if (273 != 273) {
		int btvgtlmpkw;
		for (btvgtlmpkw = 11; btvgtlmpkw > 0; btvgtlmpkw--) {
			continue;
		}
	}
	return string("jnfseaszqpdrkzyrozy");
}

bool xdbiqga::ttdihdciclwfwmmbzdgxlmw(double ehfaapmhehizwuo, double sohel, double ratyddesxqsppt) {
	int cysivhyjbeujqki = 774;
	bool gbmyruh = true;
	string tocyysfaaqp = "lstmegpqkkjosycfnyanmdfwgyuxdsmkpxqqnexyvfkjmevtsdysqglnazavevran";
	string pthebycfvz = "fpbzklqyuiimbpnis";
	string tfaegglww = "jsptymhtyxjeexpohkxyvuczdaiht";
	bool nqzvaazf = false;
	if (string("jsptymhtyxjeexpohkxyvuczdaiht") != string("jsptymhtyxjeexpohkxyvuczdaiht")) {
		int zfbpccmmhr;
		for (zfbpccmmhr = 57; zfbpccmmhr > 0; zfbpccmmhr--) {
			continue;
		}
	}
	if (string("fpbzklqyuiimbpnis") != string("fpbzklqyuiimbpnis")) {
		int rc;
		for (rc = 88; rc > 0; rc--) {
			continue;
		}
	}
	if (true == true) {
		int igqoozz;
		for (igqoozz = 21; igqoozz > 0; igqoozz--) {
			continue;
		}
	}
	if (string("lstmegpqkkjosycfnyanmdfwgyuxdsmkpxqqnexyvfkjmevtsdysqglnazavevran") == string("lstmegpqkkjosycfnyanmdfwgyuxdsmkpxqqnexyvfkjmevtsdysqglnazavevran")) {
		int bgmbeb;
		for (bgmbeb = 48; bgmbeb > 0; bgmbeb--) {
			continue;
		}
	}
	if (string("fpbzklqyuiimbpnis") != string("fpbzklqyuiimbpnis")) {
		int qtkd;
		for (qtkd = 44; qtkd > 0; qtkd--) {
			continue;
		}
	}
	return false;
}

void xdbiqga::vldbxeizuehueu(bool zotejvlf, string wdqvdd, string ytymmpnh, double ycwnskwezzol, bool svmzr, bool ajbnuapiwgbglvm, int mvhjpsqwhu, bool efyswfxfdog) {
	int aukwjng = 4790;
	int ijsjwc = 1668;
	string cjvjxan = "dwk";
	int dxaae = 672;
	bool afvzvymgqgajfu = false;
	bool chvjtiobdvdcat = false;
	double zxgzmu = 64391;
	string fhxorbxesbqmjb = "ivhatyonamitzpzdssvullmdafqsyabjcvuanevrdqklzlgkvfutpjpwrxrcwdryymltonukrauroaiyybjzsxdkkpiu";
	if (672 != 672) {
		int dpkndq;
		for (dpkndq = 69; dpkndq > 0; dpkndq--) {
			continue;
		}
	}
	if (false == false) {
		int cmebnrhfe;
		for (cmebnrhfe = 96; cmebnrhfe > 0; cmebnrhfe--) {
			continue;
		}
	}
	if (672 != 672) {
		int cf;
		for (cf = 9; cf > 0; cf--) {
			continue;
		}
	}
	if (64391 != 64391) {
		int vos;
		for (vos = 75; vos > 0; vos--) {
			continue;
		}
	}
	if (string("dwk") == string("dwk")) {
		int kosznz;
		for (kosznz = 75; kosznz > 0; kosznz--) {
			continue;
		}
	}

}

int xdbiqga::reortwcdolvhlcyc(int mspvviexxzukz) {
	double emfxoaw = 20989;
	int fvfolxkvbtnyt = 9067;
	bool ygkjkjlixysovec = true;
	string lgwqtols = "dboyeljrbzqjjdpfcoladwowfaxrdywwqkxpbskjdeakqdogexqredlxufvwcdpvffyscfwkxiwgju";
	string timvwjbaxv = "";
	if (20989 == 20989) {
		int fjwuoprd;
		for (fjwuoprd = 42; fjwuoprd > 0; fjwuoprd--) {
			continue;
		}
	}
	if (string("") != string("")) {
		int qvujddfu;
		for (qvujddfu = 86; qvujddfu > 0; qvujddfu--) {
			continue;
		}
	}
	if (string("") != string("")) {
		int phhpirvi;
		for (phhpirvi = 35; phhpirvi > 0; phhpirvi--) {
			continue;
		}
	}
	if (9067 == 9067) {
		int opbpdc;
		for (opbpdc = 100; opbpdc > 0; opbpdc--) {
			continue;
		}
	}
	return 7987;
}

xdbiqga::xdbiqga() {
	this->reortwcdolvhlcyc(1129);
	this->qjlulsdxggoygjd(true);
	this->jxemlqiiubpigibi(361);
	this->scwezlbtgbhhkgbcwt();
	this->azatbogojauqsmnswgvuvd(string("evjvhzfujtcpexmabcciqhzetakofmmznvybumoavuduuhtwweiwmqctyduhkboyed"), 6384, 1155, string("ikcvdgcnpqwrcvctnvnyrsmaeryzxevunbdgoklrdurrqbtfp"), string("nmpwacatphbpwwzjxlaurwrgnfudslwokvjohynrvcjbgbajunmeyxygfvjfad"));
	this->rlownditeclfhifotz(false, 2977, string("mfbbodmlcuxrorvxcy"), string("dzmvqamxkuubumixdi"), 2953, true, true, true);
	this->ttdihdciclwfwmmbzdgxlmw(10736, 12668, 5065);
	this->vldbxeizuehueu(false, string("bhlcdunmgmhxavtistkepdxipmnwgxbxcqawpqnoavxnimzlqifdmcvwmvtgigwmkpbctniigtwuvbxiuxjdkpctmxbgqswoqiwf"), string("tmnusryyjqulifohqjkepxeznqnwtfxtofkeczlravwdviklxfdkzcwtwfzqfabjdhrprgupzyejgtfobydsmuoxaph"), 28704, true, true, 1642, true);
	this->jgjckjuxhgughp(string("zitisnwtyixtsdvebealcjicnflhsksaqe"), string("laucqbdmsntpanlhgqklvndykrqqhjfxbeduirkajfogkbeipszigkmhfh"), 1774, 36548, string("qzlhtomiusjfybomqjcfvumtswzctkfsglpikokrrajzedpdwcorxhuhgwnpmmxst"), 7726);
	this->yrghbyzfyafqymfghdxsqrrlu(false, string("jgkpgwtpbjmvnumlmxbhktpgekasrvwcnacrsozughbketbmjofuliedelxhfkvgxzhyrnzjozrtyywwkabooqnlulsn"), string("rfooxqarulykjasme"), true, 4058, 88989, 91, string("zgzmdozwjcqofyh"));
	this->bkakryuuilgicugse(5145, false, false, 8010, 2630, 28345, 29314);
	this->kgblwtfdhbxe(1228, true, string("rxsokatarwtqz"), true, string("hwzzttirlfpczlfczimotloytwellktqhglublvybogmogspyorthezzqnocakamtcrnxopupanareajprwmckqh"), 6502, 891, 899, 71176, string("cpoagfsfiytkdapegtlkprrmydgiwuqfhghfbboksadrpclrngukblb"));
	this->ihyvltmjdnrjrsiiraplrftzl(string("uyaymjwhmhsgzmeiozeaeszfkrzqdbcpfhfardimuzpyrfcfnqyvkkfaqwxxrqdbnaalaflfusnbqhpxefuvyaesmv"), 6170, 31307, false, 15853, 42989, string("bufx"), true);
	this->gidkdcdvsqfdlk(1083, 3819, 66882, string("amxo"), true, 3498, 4335, 10559);
	this->bhkcdarbcjpzfytlgro(true, 23494);
	this->zjlyhwxtinrfhwzjnutoeoi();
	this->ckjundnimhxvz(3358, string("eziuvnvkylpfmbflgjgpzcnfkqnhjybaluyvvmxfsdpskzhzijyudbgatahywfkpgraheeqgu"), 3551, string("cagxbnzzbge"));
}







