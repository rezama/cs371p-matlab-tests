// ------------------------------
// projects/matlab/TestMatlab.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatlab.c++ -o TestMatlab.app
 *     valgrind TestMatlab.app >& TestMatlab.out
 */

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Matrix.h"
#include "Matlab.h"

// ----------
// TestMatlab
// ----------

/*
Most of these use a custom string constructor that was not included
in the original interface.
 */
struct TestMatlab : CppUnit::TestFixture {
    // --------
    // test_cat
    // --------

    void test_horzcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // -------------
    // test_linsolve
    // -------------

    void test_linsolve () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------
    // test_ones
    // ---------

    void test_ones () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}


    // beppo
    void test_horzcat_simple () {
        Matrix<int>  a("[1]");    
        Matrix<int>  b("[0]");

        Matrix<int> ab("[1,0]");
        Matrix<int> ba("[0,1]");
        CPPUNIT_ASSERT(ab.eq(horzcat(a,b)));
        CPPUNIT_ASSERT(ba.eq(horzcat(b,a)));        
    }

    void test_horzcat_1 () {
        Matrix<int>    a("[1,0]");
        Matrix<int>    b("[0,1]");
        Matrix<int>   ab("[1,0,0,1]");
        Matrix<int>   ba("[0,1,1,0]");
        Matrix<int>   aa("[1,0,1,0]");
        Matrix<int>   bb("[0,1,0,1]");
        Matrix<int> aabb("[1,0,1,0,0,1,0,1]");
        Matrix<int> bbaa("[0,1,0,1,1,0,1,0]");
        CPPUNIT_ASSERT(ab.eq(horzcat(a,b)));
        CPPUNIT_ASSERT(ba.eq(horzcat(b,a)));        
        CPPUNIT_ASSERT(aa.eq(horzcat(a,a)));
        CPPUNIT_ASSERT(bb.eq(horzcat(b,b)));
        CPPUNIT_ASSERT(aabb.eq(horzcat(aa,bb)));
        CPPUNIT_ASSERT(bbaa.eq(horzcat(bb,aa)));
    }

    void test_horzcat_2 () {
        Matrix<int>  A("[17,24,1,8,15;23,5,7,14,16;4,6,13,20,22]");
        Matrix<int>  B("[800,100,600;300,500,700;400,900,200]");
        Matrix<int> AB("[17,24,1,8,15,800,100,600;23,5,7,14,16,300,500,700;4,6,13,20,22,400,900,200]");
        Matrix<int> BA("[800,100,600,17,24,1,8,15;300,500,700,23,5,7,14,16;400,900,200,4,6,13,20,22]");
        CPPUNIT_ASSERT(AB.eq(horzcat(A,B)));
        CPPUNIT_ASSERT(BA.eq(horzcat(B,A)));
    }

    void test_vertcat_simple () {
        Matrix<int>  a("[1]");    
        Matrix<int>  b("[0]");

        Matrix<int> ab("[1;0]");
        Matrix<int> ba("[0;1]");
        CPPUNIT_ASSERT(ab.eq(vertcat(a,b)));
        CPPUNIT_ASSERT(ba.eq(vertcat(b,a)));        
    }

    void test_vertcat_1 () {
        Matrix<int>    a("[1;0]");
        Matrix<int>    b("[0;1]");
        Matrix<int>   ab("[1;0;0;1]");
        Matrix<int>   ba("[0;1;1;0]");
        Matrix<int>   aa("[1;0;1;0]");
        Matrix<int>   bb("[0;1;0;1]");
        Matrix<int> aabb("[1;0;1;0;0;1;0;1]");
        Matrix<int> bbaa("[0;1;0;1;1;0;1;0]");
        CPPUNIT_ASSERT(ab.eq(vertcat(a,b)));
        CPPUNIT_ASSERT(ba.eq(vertcat(b,a)));        
        CPPUNIT_ASSERT(aa.eq(vertcat(a,a)));
        CPPUNIT_ASSERT(bb.eq(vertcat(b,b)));
        CPPUNIT_ASSERT(aabb.eq(vertcat(aa,bb)));
        CPPUNIT_ASSERT(bbaa.eq(vertcat(bb,aa)));
    }

    void test_vertcat_2 () {
        Matrix<int> A("[17,24,1;23,5,7;4,6,13;10,12,19;11,18,25]");
        Matrix<int> B("[800,100,600;300,500,700;400,900,200]");
        Matrix<int> AB("[17,24,1;23,5,7;4,6,13;10,12,19;11,18,25;800,100,600;300,500,700;400,900,200]");
        Matrix<int> BA("[800,100,600;300,500,700;400,900,200;17,24,1;23,5,7;4,6,13;10,12,19;11,18,25]");
        CPPUNIT_ASSERT(AB.eq(vertcat(A,B)));
        CPPUNIT_ASSERT(BA.eq(vertcat(B,A)));
    }

    void test_diag_A () {
        Matrix<int> A("[1524,9619,2599;8259,47,8001;5384,7750,4315;9962,8174,9107;782,8687,1819;4427,845,2639;1067,3998,1456]");
        Matrix<int> ans("[1524;47;4315]");
        CPPUNIT_ASSERT(ans.eq(diag(A)));
    }

    void test_transpose_A () {
        Matrix<int> A("[1524,9619,2599;8259,47,8001;5384,7750,4315;9962,8174,9107;782,8687,1819;4427,845,2639;1067,3998,1456]");
        Matrix<int> ans("[1524,8259,5384,9962,782,4427,1067;9619,47,7750,8174,8687,845,3998;2599,8001,4315,9107,1819,2639,1456]");
        CPPUNIT_ASSERT(ans.eq(transpose(A)));
    }

    void test_tril_A () {
        Matrix<int> A("[1524,9619,2599;8259,47,8001;5384,7750,4315;9962,8174,9107;782,8687,1819;4427,845,2639;1067,3998,1456]");
        Matrix<int> ans("[1524,0,0;8259,47,0;5384,7750,4315;9962,8174,9107;782,8687,1819;4427,845,2639;1067,3998,1456]");
        CPPUNIT_ASSERT(ans.eq(tril(A)));
    }

    void test_triu_A () {
        Matrix<int> A("[1524,9619,2599;8259,47,8001;5384,7750,4315;9962,8174,9107;782,8687,1819;4427,845,2639;1067,3998,1456]");
        Matrix<int> ans("[1524,9619,2599;0,47,8001;0,0,4315;0,0,0;0,0,0;0,0,0;0,0,0]");
        CPPUNIT_ASSERT(ans.eq(triu(A)));
    }

    void test_diag_B () {
        Matrix<int> B("[5725,26170,5188,39747,4679,5552,14858,30783,7950;36571,14765,7737,20651,32825,39632,34547,27251,28892;24388,21592,10095,20583,16396,40224,649,18970,7721;23133,16904,17555,14208,10168,24199,1810,23013,15502;6099,3196,2089,37865,16993,2515,7110,12466,26320;35887,10094,37977,15534,4058,9877,27308,31329,32824]");
        Matrix<int> ans("[5725;14765;10095;14208;16993;9877]");
        CPPUNIT_ASSERT(ans.eq(diag(B)));
    }

    void test_transpose_B () {
        Matrix<int> B("[5725,26170,5188,39747,4679,5552,14858,30783,7950;36571,14765,7737,20651,32825,39632,34547,27251,28892;24388,21592,10095,20583,16396,40224,649,18970,7721;23133,16904,17555,14208,10168,24199,1810,23013,15502;6099,3196,2089,37865,16993,2515,7110,12466,26320;35887,10094,37977,15534,4058,9877,27308,31329,32824]");
        Matrix<int> ans("[5725,36571,24388,23133,6099,35887;26170,14765,21592,16904,3196,10094;5188,7737,10095,17555,2089,37977;39747,20651,20583,14208,37865,15534;4679,32825,16396,10168,16993,4058;5552,39632,40224,24199,2515,9877;14858,34547,649,1810,7110,27308;30783,27251,18970,23013,12466,31329;7950,28892,7721,15502,26320,32824]");
        CPPUNIT_ASSERT(ans.eq(transpose(B)));
    }

    void test_tril_B () {
        Matrix<int> B("[5725,26170,5188,39747,4679,5552,14858,30783,7950;36571,14765,7737,20651,32825,39632,34547,27251,28892;24388,21592,10095,20583,16396,40224,649,18970,7721;23133,16904,17555,14208,10168,24199,1810,23013,15502;6099,3196,2089,37865,16993,2515,7110,12466,26320;35887,10094,37977,15534,4058,9877,27308,31329,32824]");
        Matrix<int> ans("[5725,0,0,0,0,0,0,0,0;36571,14765,0,0,0,0,0,0,0;24388,21592,10095,0,0,0,0,0,0;23133,16904,17555,14208,0,0,0,0,0;6099,3196,2089,37865,16993,0,0,0,0;35887,10094,37977,15534,4058,9877,0,0,0]");
        CPPUNIT_ASSERT(ans.eq(tril(B)));
    }

    void test_triu_B () {
        Matrix<int> B("[5725,26170,5188,39747,4679,5552,14858,30783,7950;36571,14765,7737,20651,32825,39632,34547,27251,28892;24388,21592,10095,20583,16396,40224,649,18970,7721;23133,16904,17555,14208,10168,24199,1810,23013,15502;6099,3196,2089,37865,16993,2515,7110,12466,26320;35887,10094,37977,15534,4058,9877,27308,31329,32824]");
        Matrix<int> ans("[5725,26170,5188,39747,4679,5552,14858,30783,7950;0,14765,7737,20651,32825,39632,34547,27251,28892;0,0,10095,20583,16396,40224,649,18970,7721;0,0,0,14208,10168,24199,1810,23013,15502;0,0,0,0,16993,2515,7110,12466,26320;0,0,0,0,0,9877,27308,31329,32824]");
        CPPUNIT_ASSERT(ans.eq(triu(B)));
    }

    void test_diag_C () {
        Matrix<int> C("[55,291,341,253,626,391,154,114,615,653,273,474,213,175,487,306,155,264,590,175;619,298,545,541,584,139,563,152,287,293,397,148,283,534,326,642,326,245,609,224;517,205,530,355,367,201,130,291,124,75,175,79,339,20,386,365,416,658,531,453;325,339,430,234,415,314,151,208,603,172,402,198,57,619,159,348,453,26,66,91]");
        Matrix<int> ans("[55;298;530;234]");
        CPPUNIT_ASSERT(ans.eq(diag(C)));
    }

    void test_transpose_C () {
        Matrix<int> C("[55,291,341,253,626,391,154,114,615,653,273,474,213,175,487,306,155,264,590,175;619,298,545,541,584,139,563,152,287,293,397,148,283,534,326,642,326,245,609,224;517,205,530,355,367,201,130,291,124,75,175,79,339,20,386,365,416,658,531,453;325,339,430,234,415,314,151,208,603,172,402,198,57,619,159,348,453,26,66,91]");
        Matrix<int> ans("[55,619,517,325;291,298,205,339;341,545,530,430;253,541,355,234;626,584,367,415;391,139,201,314;154,563,130,151;114,152,291,208;615,287,124,603;653,293,75,172;273,397,175,402;474,148,79,198;213,283,339,57;175,534,20,619;487,326,386,159;306,642,365,348;155,326,416,453;264,245,658,26;590,609,531,66;175,224,453,91]");
        CPPUNIT_ASSERT(ans.eq(transpose(C)));
    }

    void test_tril_C () {
        Matrix<int> C("[55,291,341,253,626,391,154,114,615,653,273,474,213,175,487,306,155,264,590,175;619,298,545,541,584,139,563,152,287,293,397,148,283,534,326,642,326,245,609,224;517,205,530,355,367,201,130,291,124,75,175,79,339,20,386,365,416,658,531,453;325,339,430,234,415,314,151,208,603,172,402,198,57,619,159,348,453,26,66,91]");
        Matrix<int> ans("[55,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;619,298,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;517,205,530,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;325,339,430,234,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]");
        CPPUNIT_ASSERT(ans.eq(tril(C)));
    }

    void test_triu_C () {
        Matrix<int> C("[55,291,341,253,626,391,154,114,615,653,273,474,213,175,487,306,155,264,590,175;619,298,545,541,584,139,563,152,287,293,397,148,283,534,326,642,326,245,609,224;517,205,530,355,367,201,130,291,124,75,175,79,339,20,386,365,416,658,531,453;325,339,430,234,415,314,151,208,603,172,402,198,57,619,159,348,453,26,66,91]");
        Matrix<int> ans("[55,291,341,253,626,391,154,114,615,653,273,474,213,175,487,306,155,264,590,175;0,298,545,541,584,139,563,152,287,293,397,148,283,534,326,642,326,245,609,224;0,0,530,355,367,201,130,291,124,75,175,79,339,20,386,365,416,658,531,453;0,0,0,234,415,314,151,208,603,172,402,198,57,619,159,348,453,26,66,91]");
        CPPUNIT_ASSERT(ans.eq(triu(C)));
    }

    void test_diag_D () {
        Matrix<int> D("[35,1,6,26,19,24;3,32,7,21,23,25;31,9,2,22,27,20;8,28,33,17,10,15;30,5,34,12,14,16;4,36,29,13,18,11]");
        Matrix<int> ans("[35;32;2;17;14;11]");
        CPPUNIT_ASSERT(ans.eq(diag(D)));
    }

    void test_transpose_D () {
        Matrix<int> D("[35,1,6,26,19,24;3,32,7,21,23,25;31,9,2,22,27,20;8,28,33,17,10,15;30,5,34,12,14,16;4,36,29,13,18,11]");
        Matrix<int> ans("[35,3,31,8,30,4;1,32,9,28,5,36;6,7,2,33,34,29;26,21,22,17,12,13;19,23,27,10,14,18;24,25,20,15,16,11]");
        CPPUNIT_ASSERT(ans.eq(transpose(D)));
    }

    void test_tril_D () {
        Matrix<int> D("[35,1,6,26,19,24;3,32,7,21,23,25;31,9,2,22,27,20;8,28,33,17,10,15;30,5,34,12,14,16;4,36,29,13,18,11]");
        Matrix<int> ans("[35,0,0,0,0,0;3,32,0,0,0,0;31,9,2,0,0,0;8,28,33,17,0,0;30,5,34,12,14,0;4,36,29,13,18,11]");
        CPPUNIT_ASSERT(ans.eq(tril(D)));
    }

    void test_triu_D () {
        Matrix<int> D("[35,1,6,26,19,24;3,32,7,21,23,25;31,9,2,22,27,20;8,28,33,17,10,15;30,5,34,12,14,16;4,36,29,13,18,11]");
        Matrix<int> ans("[35,1,6,26,19,24;0,32,7,21,23,25;0,0,2,22,27,20;0,0,0,17,10,15;0,0,0,0,14,16;0,0,0,0,0,11]");
        CPPUNIT_ASSERT(ans.eq(triu(D)));
    }


    void test_eye_1 () {
        Matrix<int> ans("[1,0,0,0,0,0,0,0,0;0,1,0,0,0,0,0,0,0;0,0,1,0,0,0,0,0,0;0,0,0,1,0,0,0,0,0;0,0,0,0,1,0,0,0,0;0,0,0,0,0,1,0,0,0;0,0,0,0,0,0,1,0,0]");
        Matrix<int> r = eye< Matrix<int> >(7,9);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_eye_2 () {
        Matrix<int> ans("[1,0,0;0,1,0;0,0,1;0,0,0;0,0,0;0,0,0]");
        Matrix<int> r = eye< Matrix<int> >(6,3);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_eye_3 () {
        Matrix<int> ans("[1,0,0,0,0,0,0,0;0,1,0,0,0,0,0,0;0,0,1,0,0,0,0,0;0,0,0,1,0,0,0,0;0,0,0,0,1,0,0,0;0,0,0,0,0,1,0,0;0,0,0,0,0,0,1,0;0,0,0,0,0,0,0,1]");
        Matrix<int> r = eye< Matrix<int> >(8,8);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_ones_1 () {
        Matrix<int> ans("[1,1,1,1,1,1,1,1,1,1;1,1,1,1,1,1,1,1,1,1]");
        Matrix<int> r = ones< Matrix<int> >(2,10);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_ones_2 () {
        Matrix<int> ans("[1,1,1;1,1,1;1,1,1;1,1,1;1,1,1;1,1,1;1,1,1;1,1,1]");
        Matrix<int> r = ones< Matrix<int> >(8,3);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_ones_3 () {
        Matrix<int> ans("[1,1,1,1,1,1,1;1,1,1,1,1,1,1;1,1,1,1,1,1,1;1,1,1,1,1,1,1;1,1,1,1,1,1,1;1,1,1,1,1,1,1;1,1,1,1,1,1,1]");
        Matrix<int> r = ones< Matrix<int> >(7,7);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_zeros_1 () {
        Matrix<int> ans("[0,0,0,0,0,0,0,0,0,0;0,0,0,0,0,0,0,0,0,0]");
        Matrix<int> r = zeros< Matrix<int> >(2,10);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_zeros_2 () {
        Matrix<int> ans("[0,0,0;0,0,0;0,0,0;0,0,0;0,0,0;0,0,0;0,0,0;0,0,0]");
        Matrix<int> r = zeros< Matrix<int> >(8,3);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_zeros_3 () {
        Matrix<int> ans("[0,0,0,0,0,0,0;0,0,0,0,0,0,0;0,0,0,0,0,0,0;0,0,0,0,0,0,0;0,0,0,0,0,0,0;0,0,0,0,0,0,0;0,0,0,0,0,0,0]");
        Matrix<int> r = zeros< Matrix<int> >(7,7);
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_dot_A () {
        Matrix<int> AL("[1,2,3]");
        Matrix<int> AR("[4,5,6]");
        Matrix<int> ans("[32]");
        CPPUNIT_ASSERT(ans.eq(dot(AL,AR)));
        CPPUNIT_ASSERT(ans.eq(dot(AR,AL)));
    }

    void test_dot_B () {
        Matrix<int> BL("[1,2,3,4,5;6,7,8,9,0]");
        Matrix<int> BR("[0,9,8,7,6;5,4,3,2,1]");
        Matrix<int> ans("[30,46,48,46,30]");
        CPPUNIT_ASSERT(ans.eq(dot(BL,BR)));
        CPPUNIT_ASSERT(ans.eq(dot(BR,BL)));
    }

    void test_dot_C () {
        Matrix<int> CL("[1;2;3;4;5]");
        Matrix<int> CR("[6;7;8;9;0]");
        Matrix<int> ans("[80]");
        CPPUNIT_ASSERT(ans.eq(dot(CL,CR)));
        CPPUNIT_ASSERT(ans.eq(dot(CR,CL)));
    }

    void test_dot_D () {
        Matrix<int> D("[17,24,1,8,15;23,5,7,14,16;4,6,13,20,22;10,12,19,21,3;11,18,25,2,9]");
        Matrix<int> ans("[1055,1105,1205,1105,1055]");
        CPPUNIT_ASSERT(ans.eq(dot(D,D)));
    }

    void test_dot_E () {
        Matrix<int> EL("[491,109,311,155,299,861;182,615,503,546,853,555;653,810,612,678,973,350]");
        Matrix<int> ER("[771,658,181,919,306,463;313,640,329,729,618,989;961,255,872,752,829,180]");
        Matrix<int> ans("[1063060,671872,755442,1050335,1425265,1010538]");
        CPPUNIT_ASSERT(ans.eq(dot(EL,ER)));
    }

    void test_dot_E_2 () {
        Matrix<int> EL("[491,109,311,155,299,861;182,615,503,546,853,555;653,810,612,678,973,350]");
        Matrix<int> ET("[-711,-346,-253,-713,-901,-527;-539,-499,-227,-593,-901,-124;-945,-523,-289,-322,-757,-360]");
        Matrix<int> ans("[-1064284,-768229,-369732,-652609,-1774513,-648567]");
        CPPUNIT_ASSERT(ans.eq(dot(EL,ET)));
    }

    void test_dot_F () {
        Matrix<int> FL("[-719,-770,-945,-601;-737,-920,-473,-645;-234,-245,-743,-256;-179,-473,-255,-390;-424,-146,-828,-813]");
        Matrix<int> FR("[-713,-867,-951,-672;-879,-571,-275,-520;-395,-182,-593,-359;-486,-503,-655,-215;-847,-970,-289,-704]");
        Matrix<int> ans("[1699022,1617039,1875686,1487378]");
        CPPUNIT_ASSERT(ans.eq(dot(FL,FR)));
    }

    void test_dot_F_2 () {
        Matrix<int> FL("[-719,-770,-945,-601;-737,-920,-473,-645;-234,-245,-743,-256;-179,-473,-255,-390;-424,-146,-828,-813]");
        Matrix<int> FT("[685,378,803,755;977,337,276,548;168,782,993,828;628,995,822,420;472,267,481,165]");
        Matrix<int> ans("[-1564416,-1302307,-2235060,-1317128]");
        CPPUNIT_ASSERT(ans.eq(dot(FL,FT)));
    }

    void test_dot_G () {
        Matrix<int> D("[1,2,3,4,5]");
        Matrix<int> E("[1;2;3;4;5]");
        Matrix<int> ans(1,1,55);
        CPPUNIT_ASSERT(ans.eq(dot(D,D)));
        CPPUNIT_ASSERT(ans.eq(dot(D,E)));
        CPPUNIT_ASSERT(ans.eq(dot(E,D)));
        CPPUNIT_ASSERT(ans.eq(dot(E,E)));
    }

    void test_rand_simple_int () {
        Matrix<int> A = rand< Matrix<int> >(5,5);
        Matrix<int> B = rand< Matrix<int> >(5,5);
        CPPUNIT_ASSERT(A.size() == B.size());
        CPPUNIT_ASSERT(A[0].size() == B[0].size());
        CPPUNIT_ASSERT(!A.eq(B));
    }

    void test_rand_simple_double () {
        Matrix<double> A = rand< Matrix<double> >(5,5);
        Matrix<double> B = rand< Matrix<double> >(5,5);
        CPPUNIT_ASSERT(A.size() == B.size());
        CPPUNIT_ASSERT(A[0].size() == B[0].size());
        CPPUNIT_ASSERT(!A.eq(B));
    }

    void test_rand_simple_int_2 () {
        Matrix<int> A = rand< Matrix<int> >(1,67);
        Matrix<int> B = rand< Matrix<int> >(1,67);
        CPPUNIT_ASSERT(A.size() == B.size());
        CPPUNIT_ASSERT(A[0].size() == B[0].size());
        CPPUNIT_ASSERT(!A.eq(B));
    }

    void test_rand_simple_double_2 () {
        Matrix<double> A = rand< Matrix<double> >(1,67);
        Matrix<double> B = rand< Matrix<double> >(1,67);
        CPPUNIT_ASSERT(A.size() == B.size());
        CPPUNIT_ASSERT(A[0].size() == B[0].size());
        CPPUNIT_ASSERT(!A.eq(B));
    }

    void test_rand_simple_int_3 () {
        Matrix<int> A = rand< Matrix<int> >(69,1);
        Matrix<int> B = rand< Matrix<int> >(69,1);
        CPPUNIT_ASSERT(A.size() == B.size());
        CPPUNIT_ASSERT(A[0].size() == B[0].size());
        CPPUNIT_ASSERT(!A.eq(B));
    }

    void test_rand_simple_double_3 () {
        Matrix<double> A = rand< Matrix<double> >(69,1);
        Matrix<double> B = rand< Matrix<double> >(69,1);
        CPPUNIT_ASSERT(A.size() == B.size());
        CPPUNIT_ASSERT(A[0].size() == B[0].size());
        CPPUNIT_ASSERT(!A.eq(B));
    }

    void t_rand_seeded_int (size_t r, size_t c, unsigned s) {
        Matrix<int> A = rand< Matrix<int> >(r,c,s);

        srand(s);
        for (size_t i = 0; i < r; ++i) {
            for (size_t j = 0; j < c; ++j) {
                rand();
                CPPUNIT_ASSERT(rand() == A[i][j]);
            }
        }
    }

    void t_rand_seeded_double (size_t r, size_t c, unsigned s) {
        Matrix<double> A = rand< Matrix<double> >(r,c,s);

        srand(s);
        for (size_t i = 0; i < r; ++i) {
            for (size_t j = 0; j < c; ++j) {
                CPPUNIT_ASSERT((((double) rand()) / RAND_MAX) == A[i][j]);
            }
        }
    }

    void test_rand_seeded_int_1 () {
        t_rand_seeded_int(3,7,156168);
    }

    void test_rand_seeded_int_2 () {
        t_rand_seeded_int(38,72,568156168);
    }

    void test_rand_seeded_int_3 () {
        t_rand_seeded_int(66,12,27);
    }    

    void test_rand_seeded_int_4 () {
        t_rand_seeded_int(1,43,69420);
    }

    void test_rand_seeded_int_5 () {
        t_rand_seeded_int(33,1,448537);
    }

    void test_rand_seeded_double_1 () {
        t_rand_seeded_double(3,7,156168);
    }

    void test_rand_seeded_double_2 () {
        t_rand_seeded_double(38,72,568156168);
    }

    void test_rand_seeded_double_3 () {
        t_rand_seeded_double(66,12,27);
    }    

    void test_rand_seeded_double_4 () {
        t_rand_seeded_double(1,43,69420);
    }

    void test_rand_seeded_double_5 () {
        t_rand_seeded_double(33,1,448537);
    }

    void test_zero_dot_1 () {
        Matrix<int> A(0,0);
        Matrix<int> ans(1,1,0);
        CPPUNIT_ASSERT(ans.eq(dot(A,A)));
    }

    void test_zero_diag_1 () {
        Matrix<int> A(0,0);
        CPPUNIT_ASSERT(A.eq(diag(A)));
    }

    void test_zero_transpose_1 () {
        Matrix<int> A(0,0);
        CPPUNIT_ASSERT(A.eq(transpose(A)));
    }

    void test_zero_tril_1 () {
        Matrix<int> A(0,0);
        CPPUNIT_ASSERT(A.eq(tril(A)));
    }

    void test_zero_triu_1 () {
        Matrix<int> A(0,0);
        CPPUNIT_ASSERT(A.eq(triu(A)));
    }

    void test_zero_dot_2 () {
        Matrix<int> A(4,0);
        Matrix<int> ans(1,0);
        CPPUNIT_ASSERT(ans.eq(dot(A,A)));
    }

    void test_zero_diag_2 () {
        Matrix<int> A(4,0);
        Matrix<int> ans(0,0);
        CPPUNIT_ASSERT(ans.eq(diag(A)));
    }

    void test_zero_transpose_2 () {
        Matrix<int> A(4,0);
        Matrix<int> ans(0,4);
        CPPUNIT_ASSERT(ans.eq(transpose(A)));
    }

    void test_zero_tril_2 () {
        Matrix<int> A(4,0);
        CPPUNIT_ASSERT(A.eq(tril(A)));
    }

    void test_zero_triu_2 () {
        Matrix<int> A(4,0);
        CPPUNIT_ASSERT(A.eq(triu(A)));
    }

    void test_zero_dot_3 () {
        Matrix<int> A(0,4);
        Matrix<int> ans(1,4,0);       
        CPPUNIT_ASSERT(ans.eq(dot(A,A)));
    }

    void test_zero_diag_3 () {
        Matrix<int> A(0,4);
        Matrix<int> ans(0,0);
        CPPUNIT_ASSERT(ans.eq(diag(A)));
    }

    void test_zero_transpose_3 () {
        Matrix<int> A(0,4);
        Matrix<int> ans(4,0);
        CPPUNIT_ASSERT(ans.eq(transpose(A)));
    }

    void test_zero_tril_3 () {
        Matrix<int> A(0,4);
        CPPUNIT_ASSERT(A.eq(tril(A)));
    }

    void test_zero_triu_3 () {
        Matrix<int> A(0,4);
        CPPUNIT_ASSERT(A.eq(triu(A)));
    }

    void test_zero_eye_1 () {
        Matrix<int> ans(0,0);
        CPPUNIT_ASSERT(ans.eq(eye< Matrix <int> >(0,0)));
    }

    void test_zero_eye_2 () {
        Matrix<int> ans(4,0);
        CPPUNIT_ASSERT(ans.eq(eye< Matrix <int> >(4,0)));
    }

    void test_zero_eye_3 () {
        Matrix<int> ans(0,4);
        CPPUNIT_ASSERT(ans.eq(eye< Matrix <int> >(0,4)));
    }

    void test_zero_ones_1 () {
        Matrix<int> ans(0,0);
        CPPUNIT_ASSERT(ans.eq(ones< Matrix <int> >(0,0)));
    }

    void test_zero_ones_2 () {
        Matrix<int> ans(4,0);
        CPPUNIT_ASSERT(ans.eq(ones< Matrix <int> >(4,0)));
    }

    void test_zero_ones_3 () {
        Matrix<int> ans(0,4);
        CPPUNIT_ASSERT(ans.eq(ones< Matrix <int> >(0,4)));
    }

    void test_zero_zeros_1 () {
        Matrix<int> ans(0,0);
        CPPUNIT_ASSERT(ans.eq(zeros< Matrix <int> >(0,0)));
    }

    void test_zero_zeros_2 () {
        Matrix<int> ans(4,0);
        CPPUNIT_ASSERT(ans.eq(zeros< Matrix <int> >(4,0)));
    }

    void test_zero_zeros_3 () {
        Matrix<int> ans(0,4);
        CPPUNIT_ASSERT(ans.eq(zeros< Matrix <int> >(0,4)));
    }

    void test_diag_expansion_1 () {
        Matrix<int> A("[1,2,3,4]");
        Matrix<int> r = diag(A);
        Matrix<int> ans("[1,0,0,0;0,2,0,0;0,0,3,0;0,0,0,4]");
        CPPUNIT_ASSERT(ans.eq(r));
    }    
    void test_diag_expansion_2 () {
        Matrix<int> B("[1]");
        Matrix<int> r = diag(B);
        Matrix<int> ans("[1]");
        CPPUNIT_ASSERT(ans.eq(r));
    }    
    void test_diag_expansion_3 () {
        Matrix<int> C("[1;2;3;4;5]");
        Matrix<int> r = diag(C);
        Matrix<int> ans("[1,0,0,0,0;0,2,0,0,0;0,0,3,0,0;0,0,0,4,0;0,0,0,0,5]");
        CPPUNIT_ASSERT(ans.eq(r));
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    // CPPUNIT_TEST(test_horzcat);
    // CPPUNIT_TEST(test_vertcat);
    // CPPUNIT_TEST(test_diag);
    // CPPUNIT_TEST(test_eye);
    // CPPUNIT_TEST(test_linsolve);
    // CPPUNIT_TEST(test_ones);
    // CPPUNIT_TEST(test_rand);
    // CPPUNIT_TEST(test_transpose);
    // CPPUNIT_TEST(test_tril);
    // CPPUNIT_TEST(test_triu);
    // CPPUNIT_TEST(test_zeros);

    CPPUNIT_TEST(test_horzcat_simple);
    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);

    CPPUNIT_TEST(test_vertcat_simple);
    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);

    CPPUNIT_TEST(test_diag_A);
    CPPUNIT_TEST(test_transpose_A);
    CPPUNIT_TEST(test_tril_A);
    CPPUNIT_TEST(test_triu_A);

    CPPUNIT_TEST(test_diag_B);
    CPPUNIT_TEST(test_transpose_B);
    CPPUNIT_TEST(test_tril_B);
    CPPUNIT_TEST(test_triu_B);

    CPPUNIT_TEST(test_diag_C);
    CPPUNIT_TEST(test_transpose_C);
    CPPUNIT_TEST(test_tril_C);
    CPPUNIT_TEST(test_triu_C);

    CPPUNIT_TEST(test_diag_D);
    CPPUNIT_TEST(test_transpose_D);
    CPPUNIT_TEST(test_tril_D);
    CPPUNIT_TEST(test_triu_D);

    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);

    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);

    CPPUNIT_TEST(test_zeros_1);
    CPPUNIT_TEST(test_zeros_2);
    CPPUNIT_TEST(test_zeros_3);

    CPPUNIT_TEST(test_dot_A);
    CPPUNIT_TEST(test_dot_B);
    CPPUNIT_TEST(test_dot_C);
    CPPUNIT_TEST(test_dot_D);
    CPPUNIT_TEST(test_dot_E);
    CPPUNIT_TEST(test_dot_E_2);
    CPPUNIT_TEST(test_dot_F);
    CPPUNIT_TEST(test_dot_F_2);
    CPPUNIT_TEST(test_dot_G);

    CPPUNIT_TEST(test_rand_simple_int);
    CPPUNIT_TEST(test_rand_simple_int_2);
    CPPUNIT_TEST(test_rand_simple_int_3);
    CPPUNIT_TEST(test_rand_simple_double);
    CPPUNIT_TEST(test_rand_simple_double_2);
    CPPUNIT_TEST(test_rand_simple_double_3);

    CPPUNIT_TEST(test_rand_seeded_int_1);
    CPPUNIT_TEST(test_rand_seeded_int_2);
    CPPUNIT_TEST(test_rand_seeded_int_3);
    CPPUNIT_TEST(test_rand_seeded_int_4);
    CPPUNIT_TEST(test_rand_seeded_int_5);
    CPPUNIT_TEST(test_rand_seeded_double_1);
    CPPUNIT_TEST(test_rand_seeded_double_2);
    CPPUNIT_TEST(test_rand_seeded_double_3);
    CPPUNIT_TEST(test_rand_seeded_double_4);
    CPPUNIT_TEST(test_rand_seeded_double_5);

    CPPUNIT_TEST(test_zero_dot_1);
    CPPUNIT_TEST(test_zero_diag_1);
    CPPUNIT_TEST(test_zero_transpose_1);
    CPPUNIT_TEST(test_zero_tril_1);
    CPPUNIT_TEST(test_zero_triu_1);

    CPPUNIT_TEST(test_zero_dot_2);
    CPPUNIT_TEST(test_zero_diag_2);
    CPPUNIT_TEST(test_zero_transpose_2);
    CPPUNIT_TEST(test_zero_tril_2);
    CPPUNIT_TEST(test_zero_triu_2);

    CPPUNIT_TEST(test_zero_dot_3);
    CPPUNIT_TEST(test_zero_diag_3);
    CPPUNIT_TEST(test_zero_transpose_3);
    CPPUNIT_TEST(test_zero_tril_3);
    CPPUNIT_TEST(test_zero_triu_3);

    CPPUNIT_TEST(test_zero_eye_1);
    CPPUNIT_TEST(test_zero_eye_2);
    CPPUNIT_TEST(test_zero_eye_3);

    CPPUNIT_TEST(test_zero_ones_1);
    CPPUNIT_TEST(test_zero_ones_2);
    CPPUNIT_TEST(test_zero_ones_3);

    CPPUNIT_TEST(test_zero_zeros_1);
    CPPUNIT_TEST(test_zero_zeros_2);
    CPPUNIT_TEST(test_zero_zeros_3);

    CPPUNIT_TEST(test_diag_expansion_1);
    CPPUNIT_TEST(test_diag_expansion_2);
    CPPUNIT_TEST(test_diag_expansion_3);

    // linsolve

    CPPUNIT_TEST_SUITE_END();};

// --------------
// TestExceptions
// --------------

/*
Optionally tests exception cases for Matlab methods.
 */
template <typename T>
struct TestExceptions : CppUnit::TestFixture {

    void test_horzcat_zero () {
        Matrix<T> A(5,0);
        Matrix<T> B(5,5);
        Matrix<T> r = horzcat(A,B);
        CPPUNIT_ASSERT(r.eq(B));
    }

    void test_horzcat_zero_2 () {
        Matrix<T> A(5,5);
        Matrix<T> B(5,0);
        Matrix<T> r = horzcat(A,B);
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_horzcat_bad () {
        Matrix<T> A(4,5);
        Matrix<T> B(5,5);
        try {
            Matrix<T> r = horzcat(A,B);
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_horzcat_bad_2 () {
        Matrix<T> A(5,5);
        Matrix<T> B(4,5);
        try {
            Matrix<T> r = horzcat(A,B);
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_vertcat_zero () {
        Matrix<T> A(0,5);
        Matrix<T> B(5,5);
        Matrix<T> r = vertcat(A,B);
        CPPUNIT_ASSERT(r.eq(B));
    }

    void test_vertcat_zero_2 () {
        Matrix<T> A(5,5);
        Matrix<T> B(0,5);
        Matrix<T> r = vertcat(A,B);
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_vertcat_bad () {
        Matrix<T> A(5,4);
        Matrix<T> B(5,5);
        try {
            Matrix<T> r = vertcat(A,B);
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_vertcat_bad_2 () {
        Matrix<T> A(5,5);
        Matrix<T> B(5,4);
        try {
            Matrix<T> r = vertcat(A,B);
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_dot_zero () {
        Matrix<T> A(5,5);
        Matrix<T> B(5,5);
        Matrix<T> ans(1,5,0);
        Matrix<T> r = dot(A,B);
        CPPUNIT_ASSERT(r.eq(ans));
    }

    void test_dot_zero_2 () {
        Matrix<T> A(0,5);
        Matrix<T> B(0,5);
        Matrix<T> ans(1,5,0);
        Matrix<T> r = dot(A,B);
        CPPUNIT_ASSERT(r.eq(ans));
    }

    void test_dot_zero_3 () {
        Matrix<T> A(5,0);
        Matrix<T> B(5,0);
        Matrix<T> ans(1,0,0);
        Matrix<T> r = dot(A,B);
        CPPUNIT_ASSERT(r.eq(ans));
    }

    void test_dot_bad () {
        Matrix<T> A(5,4);
        Matrix<T> B(5,5);
        try {
            Matrix<T> r = dot(A,B);
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_dot_bad_2 () {
        Matrix<T> A(5,5);
        Matrix<T> B(5,4);
        try {
            Matrix<T> r = dot(A,B);
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    CPPUNIT_TEST_SUITE(TestExceptions);
    CPPUNIT_TEST(test_horzcat_zero);
    CPPUNIT_TEST(test_horzcat_zero_2);
    CPPUNIT_TEST(test_horzcat_bad);
    CPPUNIT_TEST(test_horzcat_bad_2);

    CPPUNIT_TEST(test_vertcat_zero);
    CPPUNIT_TEST(test_vertcat_zero_2);
    CPPUNIT_TEST(test_vertcat_bad);
    CPPUNIT_TEST(test_vertcat_bad_2);

    CPPUNIT_TEST(test_dot_zero);
    CPPUNIT_TEST(test_dot_zero_2);
    CPPUNIT_TEST(test_dot_zero_3);
    CPPUNIT_TEST(test_dot_bad);
    CPPUNIT_TEST(test_dot_bad_2);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestMatlab.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestMatlab::suite());
    tr.addTest(TestExceptions<int>::suite());
    tr.addTest(TestExceptions<double>::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}