#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Convert{
public:
    string i2slx(int i){ // int to string as long long hexel-format
        char strbuf[20];   
        string s;
        sprintf(strbuf ,"0x%llxULL",(long long int)i);
        s = strbuf;
        return s;
    }

    string i2sx(int i){ // int to string as hexel-format
        char strbuf[20];
        string s;
        sprintf(strbuf ,"0x%x",i);
        s = strbuf;
        return s;
    }

    string i2s(int i){
        char strbuf[11];
        string s;
        sprintf(strbuf ,"%d",i);
        s = strbuf;
        return s;
    }

    string i2mask(int i){
        string s;
        if(i<33){
            unsigned int mask;
            //mask = (unsigned int)(pow(2.0,(double)i)-1.0);
            mask = (1U << i) - 1;
            char strbuf[8];
            snprintf(strbuf, sizeof(strbuf), "0x%X", mask);
            s = strbuf;
        }else if(i<65){
            /* FIND BUG! (if i=54,55,56,57,58,59,60,61,....) */
            /*
              unsigned long long int mask;
              mask = (unsigned long long int)(pow(2.0,(double)i)-1.0);
              char strbuf[16];
              //    sprintf(strbuf ,"0x%016llXull",mask);
              sprintf(strbuf ,"0x%016LXull",mask);
              s = strbuf;
            */

            /* AD HOCK VERSION! */ 
            switch (i){
            case 33 :{ s = "0x00000001FFFFFFFFULL"; break;}
            case 34 :{ s = "0x00000003FFFFFFFFULL"; break;}
            case 35 :{ s = "0x00000007FFFFFFFFULL"; break;}
            case 36 :{ s = "0x0000000FFFFFFFFFULL"; break;}
            case 37 :{ s = "0x0000001FFFFFFFFFULL"; break;}
            case 38 :{ s = "0x0000003FFFFFFFFFULL"; break;}
            case 39 :{ s = "0x0000007FFFFFFFFFULL"; break;}
            case 40 :{ s = "0x000000FFFFFFFFFFULL"; break;}
            case 41 :{ s = "0x000001FFFFFFFFFFULL"; break;}
            case 42 :{ s = "0x000003FFFFFFFFFFULL"; break;}
            case 43 :{ s = "0x000007FFFFFFFFFFULL"; break;}
            case 44 :{ s = "0x00000FFFFFFFFFFFULL"; break;}
            case 45 :{ s = "0x00001FFFFFFFFFFFULL"; break;}
            case 46 :{ s = "0x00003FFFFFFFFFFFULL"; break;}
            case 47 :{ s = "0x00007FFFFFFFFFFFULL"; break;}
            case 48 :{ s = "0x0000FFFFFFFFFFFFULL"; break;}
            case 49 :{ s = "0x0001FFFFFFFFFFFFULL"; break;}
            case 50 :{ s = "0x0003FFFFFFFFFFFFULL"; break;}
            case 51 :{ s = "0x0007FFFFFFFFFFFFULL"; break;}
            case 52 :{ s = "0x000FFFFFFFFFFFFFULL"; break;}
            case 53 :{ s = "0x001FFFFFFFFFFFFFULL"; break;}
            case 54 :{ s = "0x003FFFFFFFFFFFFFULL"; break;}
            case 55 :{ s = "0x007FFFFFFFFFFFFFULL"; break;}
            case 56 :{ s = "0x00FFFFFFFFFFFFFFULL"; break;}
            case 57 :{ s = "0x01FFFFFFFFFFFFFFULL"; break;}
            case 58 :{ s = "0x03FFFFFFFFFFFFFFULL"; break;}
            case 59 :{ s = "0x07FFFFFFFFFFFFFFULL"; break;}
            case 60 :{ s = "0x0FFFFFFFFFFFFFFFULL"; break;}
            case 61 :{ s = "0x1FFFFFFFFFFFFFFFULL"; break;}
            case 62 :{ s = "0x3FFFFFFFFFFFFFFFULL"; break;}
            case 63 :{ s = "0x7FFFFFFFFFFFFFFFULL"; break;}
            case 64 :{ s = "0xFFFFFFFFFFFFFFFFULL"; break;}
            default :{ cerr << "Convert i2mask: input is out of range." <<endl; exit(1);}
            }
            /* AD HOCK VERSION! -- END*/ 

        }else{
            cerr << "Convert i2lmask: input is out of range." <<endl; exit(1);
        }

        return s;
    }

    // integer to double string
    string i2ds(int i){ 
        double d;
        d = pow(2.0,(double)i);
        char strbuf[4];
        string s;
        sprintf(strbuf ,"%f",d);
        s = strbuf;
        return s;
    }

    string i2lmask(int i){
        string s;
        switch (i){
        case  0 :{ s = "0x0000000000000000ULL"; break;}
        case  1 :{ s = "0x0000000000000001ULL"; break;}
        case  2 :{ s = "0x0000000000000003ULL"; break;}
        case  3 :{ s = "0x0000000000000007ULL"; break;}
        case  4 :{ s = "0x000000000000000FULL"; break;}
        case  5 :{ s = "0x000000000000001FULL"; break;}
        case  6 :{ s = "0x000000000000003FULL"; break;}
        case  7 :{ s = "0x000000000000007FULL"; break;}
        case  8 :{ s = "0x00000000000000FFULL"; break;}
        case  9 :{ s = "0x00000000000001FFULL"; break;}
        case 10 :{ s = "0x00000000000003FFULL"; break;}
        case 11 :{ s = "0x00000000000007FFULL"; break;}
        case 12 :{ s = "0x0000000000000FFFULL"; break;}
        case 13 :{ s = "0x0000000000001FFFULL"; break;}
        case 14 :{ s = "0x0000000000003FFFULL"; break;}
        case 15 :{ s = "0x0000000000007FFFULL"; break;}
        case 16 :{ s = "0x000000000000FFFFULL"; break;}
        case 17 :{ s = "0x000000000001FFFFULL"; break;}
        case 18 :{ s = "0x000000000003FFFFULL"; break;}
        case 19 :{ s = "0x000000000007FFFFULL"; break;}
        case 20 :{ s = "0x00000000000FFFFFULL"; break;}
        case 21 :{ s = "0x00000000001FFFFFULL"; break;}
        case 22 :{ s = "0x00000000003FFFFFULL"; break;}
        case 23 :{ s = "0x00000000007FFFFFULL"; break;}
        case 24 :{ s = "0x0000000000FFFFFFULL"; break;}
        case 25 :{ s = "0x0000000001FFFFFFULL"; break;}
        case 26 :{ s = "0x0000000003FFFFFFULL"; break;}
        case 27 :{ s = "0x0000000007FFFFFFULL"; break;}
        case 28 :{ s = "0x000000000FFFFFFFULL"; break;}
        case 29 :{ s = "0x000000001FFFFFFFULL"; break;}
        case 30 :{ s = "0x000000003FFFFFFFULL"; break;}
        case 31 :{ s = "0x000000007FFFFFFFULL"; break;}
        case 32 :{ s = "0x00000000FFFFFFFFULL"; break;}
        case 33 :{ s = "0x00000001FFFFFFFFULL"; break;}
        case 34 :{ s = "0x00000003FFFFFFFFULL"; break;}
        case 35 :{ s = "0x00000007FFFFFFFFULL"; break;}
        case 36 :{ s = "0x0000000FFFFFFFFFULL"; break;}
        case 37 :{ s = "0x0000001FFFFFFFFFULL"; break;}
        case 38 :{ s = "0x0000003FFFFFFFFFULL"; break;}
        case 39 :{ s = "0x0000007FFFFFFFFFULL"; break;}
        case 40 :{ s = "0x000000FFFFFFFFFFULL"; break;}
        case 41 :{ s = "0x000001FFFFFFFFFFULL"; break;}
        case 42 :{ s = "0x000003FFFFFFFFFFULL"; break;}
        case 43 :{ s = "0x000007FFFFFFFFFFULL"; break;}
        case 44 :{ s = "0x00000FFFFFFFFFFFULL"; break;}
        case 45 :{ s = "0x00001FFFFFFFFFFFULL"; break;}
        case 46 :{ s = "0x00003FFFFFFFFFFFULL"; break;}
        case 47 :{ s = "0x00007FFFFFFFFFFFULL"; break;}
        case 48 :{ s = "0x0000FFFFFFFFFFFFULL"; break;}
        case 49 :{ s = "0x0001FFFFFFFFFFFFULL"; break;}
        case 50 :{ s = "0x0003FFFFFFFFFFFFULL"; break;}
        case 51 :{ s = "0x0007FFFFFFFFFFFFULL"; break;}
        case 52 :{ s = "0x000FFFFFFFFFFFFFULL"; break;}
        case 53 :{ s = "0x001FFFFFFFFFFFFFULL"; break;}
        case 54 :{ s = "0x003FFFFFFFFFFFFFULL"; break;}
        case 55 :{ s = "0x007FFFFFFFFFFFFFULL"; break;}
        case 56 :{ s = "0x00FFFFFFFFFFFFFFULL"; break;}
        case 57 :{ s = "0x01FFFFFFFFFFFFFFULL"; break;}
        case 58 :{ s = "0x03FFFFFFFFFFFFFFULL"; break;}
        case 59 :{ s = "0x07FFFFFFFFFFFFFFULL"; break;}
        case 60 :{ s = "0x0FFFFFFFFFFFFFFFULL"; break;}
        case 61 :{ s = "0x1FFFFFFFFFFFFFFFULL"; break;}
        case 62 :{ s = "0x3FFFFFFFFFFFFFFFULL"; break;}
        case 63 :{ s = "0x7FFFFFFFFFFFFFFFULL"; break;}
        case 64 :{ s = "0xFFFFFFFFFFFFFFFFULL"; break;}
        default :{ cerr << "Convert i2mask: input is out of range." <<endl; exit(1);}
        }
        return s;
    }
};



//  void generate_c_pg_conv_ftol_itp(vector<string> args, GenFile* gfObj)
void generate_c_pg_conv_ftol_itp()
{
    Convert conv;

    // +------------------------------+
    // | Parse C-subroutine arguments |
    // +------------------------------+

    string sx = "x";
    string sy = "z";
    int nbit_fix = 32;  // atoi(args[2].c_str());
    int nbit_log = 17;  // atoi(args[3].c_str());
    int nbit_man = 8;   // atoi(args[4].c_str());
    int nstage   = 1;   // atoi(args[5].c_str()); nstage += 0;
    int ncut     = 4;   // atoi(args[6].c_str());
    int bit_ext  = 2;   // fixed length

    if((ncut<2)||(ncut>nbit_man)){
        ncut = (int)(nbit_man/2.0 +0.5);
        cerr << "\tWorning: Set NCUT for pg_conv_ftol_itp to "+conv.i2s(ncut)+".\n";
    }


    // +------------------------------+
    // | Function Name Generation     |
    // +------------------------------+
    string func_name;
    func_name = "pg_conv_ftol_itp";
    func_name += "_fix" + conv.i2s(nbit_fix);
    func_name += "_log" + conv.i2s(nbit_log);
    func_name += "_man" + conv.i2s(nbit_man);
    func_name += "_cut" + conv.i2s(ncut);

    //cout << func_name << endl;

    //    cerr << "\tpgpgc_module generate  void ";
    //    cerr << func_name << "(int fixdata, int* logdata)"<<endl;

    // +------------------------------+
    // | Simulator Part               |
    // +------------------------------+
    string s;
    s += "/* nbit_fix   :   " + conv.i2s(nbit_fix) + "-bit      */          \n";
    s += "/* nbit_log   :   " + conv.i2s(nbit_log) + "-bit      */          \n";
    s += "/* nbit_man   :   " + conv.i2s(nbit_man) + "-bit      */          \n";
    s += "/* ncut       :   " + conv.i2s(ncut) + "-bit          */          \n";

    s += "#include<stdio.h>                                                  \n";
    s += "#include<math.h>                                                   \n";
    s += "void " + func_name + "(int fixdata, int* logdata){                 \n";
    s += "  int fixdata_msb=0;                                               \n";
    s += "  int logdata_sign=0;                                              \n";
    s += "  int fixdata_body=0;                                              \n";
    s += "  int abs=0;                                                       \n";
    s += "  int abs_decimal=0;                                               \n";
    s += "  int logdata_nonzero=0;                                           \n";
    s += "  int penc_out = 0; /* Output of penc */                           \n"; 
    s += "  int table_adr = 0;                                               \n"; 
    s += "  int table_overflow = 0;                                          \n"; 
    s += "  int logdata_mantissa=0;                                          \n";
    s += "  int logdata_exponent=0;                                          \n";

    s += "\n";
    s += "  /* SIGN BIT */                                                   \n";
    s += "  fixdata_msb = 0x1&(fixdata >>"+conv.i2s(nbit_fix-1)+");         \n";
    s += "  logdata_sign = fixdata_msb;                                      \n";


    s += "\n";
    s += "  /* ABSOLUTE */                                                   \n";
    s += "  /* ABSOLUTE */                                                   \n";
    s += "  /* ABSOLUTE */                                                   \n";
    s += "  /* ABSOLUTE */                                                   \n";
    s += "  /* ABSOLUTE */                                                   \n";
    s += "  /* ABSOLUTE */                                                   \n";
    s += "  /* ABSOLUTE */                                                   \n";

    s += "  fixdata_body    = "+conv.i2mask(nbit_fix-1)+" & fixdata;        \n";
    s += "  {                                                                \n";
    s += "    int inv_fixdata_body=0;                                        \n";
    s += "    inv_fixdata_body = "+conv.i2mask(nbit_fix-1)+" ^ fixdata_body;\n";
    s += "    if(fixdata_msb == 0x1){                                        \n";
    s += "      abs = "+conv.i2mask(nbit_fix-1)+" & (inv_fixdata_body + 1); \n";
    s += "    }else{                                                         \n";
    s += "      abs = fixdata_body;                                          \n";
    s += "    }                                                              \n";
    s += "  }                                                                \n";
    s += "  abs_decimal = "+conv.i2mask(nbit_fix-2)+"& abs;                 \n";



    s += "\n";
    s += "  /* GENELATE NON-ZERO BIT (ALL BIT OR) */                                 \n";
    s += "  if(abs != 0x0){ logdata_nonzero = 0x1; }else{ logdata_nonzero=0x0; }     \n";


    int penc_outwidth=0;
    if((nbit_fix <= 32)&&(nbit_fix > 16))      penc_outwidth=5;
    else if((nbit_fix <= 16)&&(nbit_fix > 8))  penc_outwidth=4;
    else if((nbit_fix <= 8)&&(nbit_fix > 4))   penc_outwidth=3;
    else if((nbit_fix <= 4)&&(nbit_fix > 2))   penc_outwidth=2;
    else if((nbit_fix <= 2)&&(nbit_fix > 1))   penc_outwidth=1;
    else{ cerr << "nbit_fix is out of range.\n"; exit(1); }
    s += "\n";
    s += "  { /* PRIORITY ENCODER */                                         \n";
    s += "    int i;                                                         \n";
    s += "    int count=0;                                                   \n";
    s += "    for(i=31;i >=0;i--){                                           \n";
    s += "        int buf;                                                   \n";
    s += "        buf = 0x1 & (abs >>i);                                     \n";
    s += "        if(buf == 0x1){ count = i; break;}                         \n";
    s += "        count = i;                                                 \n";
    s += "    }                                                              \n";
    s += "    penc_out=count;                                                \n";
    s += "  }                                                                \n";
    s += "  penc_out = "+conv.i2mask(penc_outwidth)+" & penc_out; /* "+conv.i2s(penc_outwidth)+"-bit */\n";
   
    s += "  \n";

    /* --- change shifter to no rounding version (2003/06/19) --- */ 
    //    s += "  /* SHIFTER */                                                                      \n";
    //    s += "  {                                                                                  \n";
    //    s += "    long long int seed,idat;\n";
    //    s += "    idat = (long long int)abs_decimal;\n";
    //    s += "    if(penc_out>="+conv.i2s(nbit_man+2)+"){                                         \n";
    //    s += "      seed = idat;\n";
    //    s += "      table_adr = (int)("+conv.i2mask(nbit_man+2)+"LL & (seed>>(penc_out-"+conv.i2s(nbit_man+2)+")));\n";
    //    s += "    }else{\n";
    //    s += "      seed = (idat<<1) | 0x1LL; /* --- rounding collection --- */\n";
    //    s += "      seed = seed << "+conv.i2s(nbit_man+1)+";\n";
    //    s += "      table_adr = "+conv.i2mask(nbit_man+2)+" & (int)(seed>>penc_out);\n";
    //    s += "    }                                                                                \n";
    //    s += "  }                                                                                  \n";
    s += "  /* SHIFTER WITH NO ROUNDING */\n";
    s += "  {\n";
    s += "    long long int seed,idat;\n";
    s += "    idat = (long long int)abs_decimal;\n";
    s += "    if(penc_out>="+conv.i2s(nbit_man+2)+"){                                         \n";
    s += "      seed = idat;\n";
    s += "      table_adr = (int)("+conv.i2mask(nbit_man+2)+"LL & (seed>>(penc_out-"+conv.i2s(nbit_man+2)+")));\n";
    s += "    }else{\n";
    s += "      /* --- no rounding collection --- */\n";
    s += "      seed = idat << "+conv.i2s(nbit_man+2)+";\n";
    s += "      table_adr = "+conv.i2mask(nbit_man+2)+" & (int)(seed>>penc_out);\n";
    s += "    }\n";
    s += "  }                                                                                  \n";

    s += "  \n";
    s += "  /* TABLE */                                                                        \n";
    s += "  /* TABLE INPUT WIDTH  = "+conv.i2s(nbit_man+2)+"-bit */                           \n";
    s += "  /* TABLE OUTPUT WIDTH = "+conv.i2s(nbit_man)+"-bit */                             \n";
    s += "  {                                                                                  \n";
    s += "    int adr,dx,rom_c0,rom_c1;\n";
    //    s += "    double adr_double=0.0;                                                           \n";
    //    s += "    double data_double=0.0;                                                          \n";
    s += "    int data;                                                                        \n";
    if(nbit_man+2 > 31){cerr << "Error : table adr width at conv_ftol_itp is out of range."; exit(1);}
    s += "    adr = "+conv.i2mask(nbit_man+2-ncut)+" & (table_adr>>"+conv.i2s(ncut)+");";
    s += "\t/* high part of table address */\n";
    s += "    dx = "+conv.i2mask(ncut)+" & table_adr;";
    s += "\t/* low part of table address */\n";
    s += "    { /* --- calc chebyshev coefficients --- */\n";
    s += "      long double xmin,xmax;\n";
    s += "      long double x0,x1,bma,bpa,c0,c1,cc0,cc1,coef0,coef1;\n";
    s += "      xmin = (long double)(adr<<"+conv.i2s(ncut)+");\n";
    s += "      xmax = (long double)(((adr+1)<<"+conv.i2s(ncut)+")-1);\n";
    s += "      xmin = (xmin+0.0)/(long double)(0x1<<"+conv.i2s(nbit_man+2)+");\n";
    s += "      xmax = (xmax+0.0)/(long double)(0x1<<"+conv.i2s(nbit_man+2)+");\n";
    s += "      x0 = -0.5*sqrtl(2.0);\n";
    s += "      x1 =  0.5*sqrtl(2.0);\n";
    s += "      bma = 0.5*(xmax-xmin);\n";
    s += "      bpa = 0.5*(xmax+xmin);\n";
    s += "      c0 = logl(1.0+x0*bma+bpa)/logl(2.0);\n";
    s += "      c1 = logl(1.0+x1*bma+bpa)/logl(2.0);\n";
    s += "      cc0 = 0.5*(c0+c1);\n";
    s += "      cc1 = 0.5*sqrtl(2.0)*(c1-c0);\n";
    s += "      coef0 = cc0 - cc1;    /* 0-dim chebyshev coefficient */\n";
    s += "      coef1 = cc1/bma;      /* 1-dim chebyshev coefficient */\n";
    s += "      rom_c0 = (int)(coef0*powl(2.0,"+conv.i2s(nbit_man+bit_ext)+".0)+0.5);\n";
    s += "      rom_c1 = (int)(coef1*powl(2.0,"+conv.i2s(nbit_man+bit_ext)+".0)+0.5);\n";
    s += "    }\n";
    int trnd;
    if(bit_ext>0) trnd = 0x1<<(bit_ext-1); else trnd = 0x0;
    s += "    data = (rom_c0+((rom_c1*dx)>>"+conv.i2s(nbit_man+2)+")+"+conv.i2s(trnd)+")>>"+conv.i2s(bit_ext)+";\n";
    s += "    table_overflow= 0x1&(data>>"+conv.i2s(nbit_man)+");\n";
    s += "    logdata_mantissa = "+conv.i2mask(nbit_man)+"&data;\n";
    s += "  }";

    s += "  \n";
    s += "  /* ADDER (GENERATE EXPONENT PART) */                                               \n";
    s += "  logdata_exponent = "+conv.i2mask(penc_outwidth)+" & (penc_out + table_overflow);  \n";

    s += "  \n";
    s += "  *logdata = logdata_sign << "+conv.i2s(nbit_log-1);
    s +=            "| logdata_nonzero << "+conv.i2s(nbit_log-2);
    s +=            "| logdata_exponent << "+conv.i2s(nbit_man);
    s +=            "| logdata_mantissa ;\n";
    s += "  \n";
    s += "  return;                                                          \n";
    s += "}                                                                  \n";



    // +------------------------------+
    // | Test Driver Part             |
    // +------------------------------+
    string test;
    test += "/* nbit_fix   :   " + conv.i2s(nbit_fix) + "-bit      */       \n";
    test += "/* nbit_log   :   " + conv.i2s(nbit_log) + "-bit      */       \n";
    test += "/* nbit_man   :   " + conv.i2s(nbit_man) + "-bit      */       \n";
    test += "#include<stdio.h>                                               \n";
    test += "#include<math.h>                                               \n";
    test += "void "+func_name+"(int fix,int* log);                           \n";
    test += "int main(){                                                     \n";
    test += "  int i;                                                        \n";
    test += "  printf(\"nbit_fix = "+ conv.i2s(nbit_fix) +"\\n\");          \n";
    test += "  printf(\"nbit_log = "+ conv.i2s(nbit_log) +"\\n\");          \n";
    test += "  printf(\"nbit_man = "+ conv.i2s(nbit_man) +"\\n\");          \n";
    test += "  for(i=0;i<="+conv.i2mask(nbit_fix)+";i++){                   \n";
    test += "    int fix=i;                                                  \n";
    test += "    int log=0;                                                  \n";
    test += "    double real_fix=0.0;                                        \n";
    test += "    double real_log=0.0;                                        \n";
    test += "    "+func_name+"(fix,&log);                                    \n";
    test += "    real_fix = (double)fix;                                     \n";
    test += "    real_log = pow(2.0,(double)("+conv.i2mask(nbit_log-2)+"&log)/pow(2.0,"+conv.i2s(nbit_man)+".0)); \n";

    test += "    if(0x1&(fix>>"+conv.i2s(nbit_fix-1)+")==0x1){   \n";
    test += "      int inv_fix = fix ^ "+conv.i2mask(nbit_fix)+";     \n";
    test += "      inv_fix++;                                     \n";
    test += "      real_fix = -1.0 * (double)inv_fix;             \n";
    test += "    }                                                \n";
    //    test += " real_fix = (double)("+conv.i2mask(nbit_fix-1)+"&fix )-(double)"+conv.i2mask(nbit_fix)+";}\n";

    test += "    if(0x1&(log>>"+conv.i2s(nbit_log-1)+")==0x1){ real_log = real_log * -1.0;}\n";
    test += "    if(0x1&(log>>"+conv.i2s(nbit_log-2)+")==0x0){ real_log = 0.0;}\n";

    test += "    printf(\"fix=0x%X,log=0x%X\\t\",fix,log);                   \n";
    test += "    printf(\"(Re)fix=%f,(Re)log=%f\\t\",real_fix,real_log);           \n";
    test += "    printf(\"Error(Abs)%f\\t\",(real_log-real_fix));\n";
    test += "    printf(\"Error(Rel)%f\\n\",(real_log-real_fix)/real_log);\n";
    test += "  }                                                             \n";
    test += "  return 1;\n                                                   \n";
    test += "}                                                               \n";

    // test driver compile shell script
    string shell;
    shell += "#!/bin/sh               \n";
    shell += "rm -rf test_"+func_name+".o "+func_name+".o test_"+func_name+"\n";
    shell += "gcc -c test_"+func_name+".c\n";
    shell += "gcc -c "+func_name+".c\n";
    shell += "gcc test_"+func_name+".o "+func_name+".o -o test_"+func_name+" -lm\n";

    //gfObj->generate(func_name,s);
    //    gfObj->generate("test_"+func_name,test);        // for debug no problem
    //    gfObj->generate("make_"+func_name,shell,".sh"); // for debug no problem

    cout << s << endl;

}

int main() {
    generate_c_pg_conv_ftol_itp();
    return 0;
}

