/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/

#include "TiePHistorical.h"



/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
aooter-MicMac-eLiSe-25/06/2007*/

/*******************************************/
/******* cCommonAppliTiepHistorical  *******/
/*******************************************/
cCommonAppliTiepHistorical::cCommonAppliTiepHistorical() :
        mArgBasic(new LArgMain),
        mArgRough(new LArgMain),
        mArgSuperGlue(new LArgMain),
        mArgMergeTiePt(new LArgMain),
        mArgGetPatchPair(new LArgMain),
        mArgGetOverlappedImages(new LArgMain),
        mArg2DRANSAC(new LArgMain),
        mArg3DRANSAC(new LArgMain),
        mArgGuidedSIFT(new LArgMain),
        mArgDSM_Equalization(new LArgMain),
        mArgCrossCorrelation(new LArgMain),
        mArgCreateGCPs(new LArgMain)
{
    mDir = "./";
    mAngle = 0;
    //mBufferSz = Pt2dr(30, 60);
    mCheckAngle = true;
    mCheckScale = true;
    mHomoXml = "SubPatch.xml";
    mImgPair = "SuperGlueInput.txt";
    mInput_dir = "./";
    mR2DIteration = 1000;
    mR3DIteration = 1000;
    mKeepNpzFile = false;
    mMax_keypoints = 1024;
    mModel = "outdoor";
    mMutualNN = true;
    //mOutImg = "";
    mOutPairXml = "OverlappedImages.xml";
    mSpGlueOutSH = "-SuperGlue";
    mGuidedSIFTOutSH = "-GuidedSIFT";
    mMergeTiePtOutSH = "";
    mR2DInSH = "";
    mR2DOutSH = "";
    mR3DInSH = "";
    mR3DOutSH = "";
    mCrossCorrelationOutSH = "";
    mMergeTiePtInSH = "";
    mCreateGCPsInSH = "";
    mCrossCorrelationInSH = "";
    //mPatchSz = Pt2dr(640, 480);
    mPredict = true;
    mRatioT = true;
    mResize = Pt2di(640, 480);
    mRootSift = true;
    mScale = 1;
    mSearchSpace = 100;
    mSkipSIFT = false;
    mSTDRange = 5;
    mSubPatchXml = "SubPatch.xml";
    mR2DThreshold = 10;
    mR3DThreshold = -1;
    mCrossCorrThreshold = 0.5;
    mWindowSize = 32;
    mViz = false;
//    mDSMFileL = "MMLastNuage.xml";
//    mDSMFileR = "MMLastNuage.xml";
//    mDSMDirL = "";
//    mDSMDirR = "";
//    mOutDir = "./Tmp_Patches";
//    mOutImg1 = "";
//    mOutImg2 = "";
    mOut2DXml1 = "OutGCP2D_epoch1.xml";
    mOut2DXml2 = "OutGCP2D_epoch2.xml";
    mOut3DXml1 = "OutGCP3D_epoch1.xml";
    mOut3DXml2 = "OutGCP3D_epoch2.xml";
    //mSubPatchLXml = "SubPL.xml";
    //mSubPatchRXml = "SubPR.xml";
    mStrEntSpG = "";
    mStrOpt = "";
    mPrint = false;
    mThreshScale = 0.2;
    mThreshAngle = 30;
    mMinPt = 10;

        *mArgBasic
            //                        << EAM(mExe,"Exe",true,"Execute all, Def=true")
                        << EAM(mPrint, "Print", false, "Print supplementary information, Def=false")
                        << EAM(mDir,"Dir",true,"Work directory, Def=./");


        *mArgRough
            << EAM(mOriIn1,"OriIn1",true,"Input Orientation of epoch1, Def=./")
            << EAM(mOriIn2,"OriIn2",true,"Input Orientation of epoch2, Def=./")
//            << EAM(mDSMDirL,"DSMDirL",true,"DSM direcotry of epoch1, Def=none")
//            << EAM(mDSMDirR,"DSMDirR",true,"DSM direcotry of epoch2, Def=none")
            << EAM(mOriOut,"OriOut",true,"Output Orientation, Def=./");



    *mArgDSM_Equalization
        //<< EAM(mDSMFileL, "DSMFile", true, "DSM File, Def=MMLastNuage.xml")
        << EAM(mSTDRange, "STDRange", true, "Only pixels with their value within STDRange times of std will be considered (in order to ignore altitude outliers), Def=5");
        //<< EAM(mOutImg, "OutImg", true, "Output image name");


    *mArgGetPatchPair
            //<< EAM(mPatchSz, "PatchSz", true, "Patch size of the tiling scheme, which means the images to be matched by SuperGlue will be split into patches of this size, Def=[640, 480]")
            //<< EAM(mBufferSz, "BufferSz", true, "Buffer zone size around the patch of the tiling scheme, Def=[30, 60]")
            << EAM(mSubPatchXml, "SubPXml", true, "The output xml file name to record the homography between the patches and original image, Def=SubPatch.xml")
            //<< EAM(mDSMDirL, "DSMDirL", true, "DSM of master image (for improving the reprojecting accuracy), Def=none")
            //<< EAM(mDSMDirR, "DSMDirR", true, "DSM of secondary image (for improving the reprojecting accuracy), Def=none")
            //<< EAM(mOutImg1, "OutImg1", true, "Name of the main part of the output patches from master image, Def=master image name")
            //<< EAM(mOutImg2, "OutImg2", true, "Name of the main part of the output patches from secondary image, Def=secondary image name")
            << EAM(mImgPair, "ImgPair", true, "Output txt file that records the patch pairs, Def=SuperGlueInput.txt");


    *mArgSuperGlue
            //<< EAM(input_pairs, "input_pairs", true, "txt file that listed the image pairs")
            << EAM(mInput_dir, "InDir", true, "The input directory of the images for SuperGlue, Def=./")
            << EAM(mSpGlueOutSH, "SpGOutSH", true, "Homologue extenion for NB/NT mode of SuperGlue, Def=-SuperGlue")
            << EAM(mResize, "Resize", true, "The goal size for resizing the input image for SuperGlue, Def=[640, 480], if you don't want to resize, please set to [-1, -1]")
            << EAM(mViz, "Viz", true, "Visualize the matches and dump the plots of SuperGlue, Def=false")
            << EAM(mModel, "Model", true, "Pretrained indoor or outdoor model of SuperGlue, Def=outdoor")
            << EAM(mMax_keypoints, "MaxPt", true, "Maximum number of keypoints detected by Superpoint, Def=1024")
            << EAM(mKeepNpzFile, "KeepNpzFile", true, "Keep the original npz file that SuperGlue outputed, Def=false")
            << EAM(mStrEntSpG, "EntSpG", true, "The SuperGlue program entry (this option is only used for developper), Def=../micmac/src/uti_phgrm/TiePHistorical/SuperGluePretrainedNetwork-master/match_pairs.py")
            << EAM(mStrOpt, "opt", true, "Other options for SuperGlue (this option is only used for developper), Def=none");

    *mArgMergeTiePt
        << EAM(mMergeTiePtInSH,"MergeInSH",true,"Input Homologue extenion for NB/NT mode for MergeTiePt, Def=none")
        << EAM(mHomoXml,"HomoXml",true,"Input xml file that recorded the homograhpy from patches to original image for MergeTiePt, Def=SubPatch.xml")
           //the name of MergeOutSH will be set as the same name of HomoXml, if not set by users
        << EAM(mMergeTiePtOutSH,"MergeOutSH",true,"Output Homologue extenion for NB/NT mode of MergeTiePt, Def=-SubPatch");


    *mArgCreateGCPs
        //<< EAM(mDSMDirL,"DSMDirL",true,"DSM direcotry of epoch1, Def=none")
        //<< EAM(mDSMDirR,"DSMDirR",true,"DSM direcotry of epoch2, Def=none")
        //<< EAM(mDSMFileL, "DSMFileL", true, "DSM File of epoch1, Def=MMLastNuage.xml")
        //<< EAM(mDSMFileR, "DSMFileR", true, "DSM File of epoch2, Def=MMLastNuage.xml")
        << EAM(mCreateGCPsInSH,"CreateGCPsInSH",true,"Input Homologue extenion for NB/NT mode for CreateGCPs, Def=none")
        << EAM(mOut2DXml1,"Out2DXml1",true,"Output xml files of 2D obersevations of the GCPs in epoch1, Def=OutGCP2D_epoch1.xml")
        << EAM(mOut3DXml1,"Out3DXml1",true,"Output xml files of 3D obersevations of the GCPs in epoch1, Def=OutGCP3D_epoch1.xml")
        << EAM(mOut2DXml2,"Out2DXml2",true,"Output xml files of 2D obersevations of the GCPs in epoch2, Def=OutGCP2D_epoch2.xml")
        << EAM(mOut3DXml2,"Out3DXml2",true,"Output xml files of 3D obersevations of the GCPs in epoch2, Def=OutGCP3D_epoch2.xml");


    *mArgGetOverlappedImages
            << EAM(mOutPairXml,"OutPairXml",true,"Output Xml file to record the overlapped image pairs, Def=OverlappedImages.xml");


    *mArg2DRANSAC
        << EAM(mR2DInSH,"2DRANInSH",true,"Input Homologue extenion for NB/NT mode for 2D RANSAC, Def=none")
        << EAM(mR2DOutSH,"2DRANOutSH",true,"Output Homologue extenion for NB/NT mode of 2D RANSAC, Def='2DRANInSH'-2DRANSAC")
        << EAM(mR2DIteration,"2DIter",true,"2D RANSAC iteration, Def=1000")
        << EAM(mR2DThreshold,"2DRANTh",true,"2D RANSAC threshold, Def=10");

    *mArg3DRANSAC
        << EAM(mR3DInSH,"3DRANInSH",true,"Input Homologue extenion for NB/NT mode for 3D RANSAC, Def=none")
        << EAM(mR3DOutSH,"3DRANOutSH",true,"Output Homologue extenion for NB/NT mode of 3D RANSAC, Def='3DRANInSH'-3DRANSAC")
        << EAM(mR3DIteration,"3DIter",true,"3D RANSAC iteration, Def=1000")
        //<< EAM(mR3DThreshold,"3DRANTh",true,"3D RANSAC threshold, Def=10*RefGSD (if \"Para3DHL\" is valid, RefGSD is the average GSD of master and secondary image, otherwise RefGSD is the GSD of secondary image)")
        << EAM(mR3DThreshold,"3DRANTh",true,"3D RANSAC threshold, Def=10*(GSD of secondary image)")
                << EAM(mMinPt,"MinPt",true,"Minimun number of input correspondences required, Def=10");
           /*
        << EAM(mDSMDirL, "DSMDirL", true, "DSM directory of master image, Def=none")
        << EAM(mDSMDirR, "DSMDirR", true, "DSM directory of secondary image, Def=none")
        << EAM(mDSMFileL, "DSMFileL", true, "DSM File of master image, Def=MMLastNuage.xml")
        << EAM(mDSMFileR, "DSMFileR", true, "DSM File of secondary image, Def=MMLastNuage.xml");
               */


    *mArgGuidedSIFT
            /*
    << EAM(mDSMDirL, "DSMDirL", true, "DSM of master image (for improving the reprojecting accuracy), Def=none")
    << EAM(mDSMDirR, "DSMDirR", true, "DSM of secondary image (for improving the reprojecting accuracy), Def=none")
    << EAM(mDSMFileL, "DSMFileL", true, "DSM File of master image, Def=MMLastNuage.xml")
    << EAM(mDSMFileR, "DSMFileR", true, "DSM File of secondary image, Def=MMLastNuage.xml")
            */
    << EAM(mGuidedSIFTOutSH,"GSIFTOutSH",true,"Output Homologue extenion for NB/NT mode of Guided SIFT, Def=-GuidedSIFT")
    << EAM(mSkipSIFT,"SkipSIFT",true,"Skip extracting SIFT key points in case it is already done, Def=false")
    << EAM(mSearchSpace,"SearchSpace",true,"Radius of the search space for GuidedSIFT (the search space is the circle with the center on the predicted point), Def=100 (this value is based on master image, the search space on secondary image will multiply the scale difference if \"CheckScale\" is set to true)")
    << EAM(mMutualNN, "MutualNN",true, "Apply mutual nearest neighbor on GuidedSIFT, Def=true")
    << EAM(mRatioT, "RatioT",true, "Apply ratio test on GuidedSIFT, Def=true")
    << EAM(mRootSift, "RootSift",true, "Use RootSIFT as descriptor on GuidedSIFT, Def=true")
    << EAM(mCheckScale, "CheckScale",true, "Check the scale of the candidate tie points on GuidedSIFT, Def=true")
    << EAM(mCheckAngle, "CheckAngle",true, "Check the angle of the candidate tie points on GuidedSIFT, Def=true")
    //<< EAM(mScale, "Scale",true, "The scale ratio used for checking the candidate tie points on GuidedSIFT, Def=1")
    //<< EAM(mAngle, "Angle",true, "The angle difference used for checking the candidate tie points on GuidedSIFT, Def=0")
    << EAM(mThreshScale, "ScaleTh",true, "The threshold for checking scale ratio, Def=0.2; (0.2 means the ratio of master and secondary SIFT scale between [(1-0.2)*Ref, (1+0.2)*Ref] is considered valide. Ref is automatically calculated by reprojection.)")
    << EAM(mThreshAngle, "AngleTh",true, "The threshold for checking angle difference, Def=30; (30 means the difference of master and secondary SIFT angle between [Ref - 30 degree, Ref + 30 degree] is considered valide. Ref is automatically calculated by reprojection.)")
    << EAM(mPredict, "Predict",true, "Use the predicted key points to guide the matching, Def=true");

    *mArgCrossCorrelation
//            << EAM(mPatchSz, "PatchSz", true, "Patch size, Def=[640, 480]")
//            << EAM(mBufferSz, "BufferSz", true, "Buffer sie, Def=[30, 60]")
            << EAM(mCrossCorrelationInSH,"CCInSH",true,"Input Homologue extenion for NB/NT mode for cross correlation, Def=none")
            << EAM(mCrossCorrelationOutSH,"CCOutSH",true,"Output Homologue extenion for NB/NT mode of cross correlation, Def='CCInSH'-CrossCorrelation")
               //<< EAM(mSubPatchXml, "SubPatchXml", true, "The xml file name to record the homography between the patch and original image, Def=SubPatch.xml")
            << EAM(mWindowSize, "SzW",true, "Window size of cross correlation, Def=32")
            << EAM(mCrossCorrThreshold, "CCTh",true, "Corss correlation threshold, Def=0.5");

        //StdCorrecNameOrient(mOutRPC,mDir,true);

    mICNM = cInterfChantierNameManipulateur::BasicAlloc(mDir);
}

LArgMain & cCommonAppliTiepHistorical::ArgBasic()
{
        return * mArgBasic;
}

LArgMain & cCommonAppliTiepHistorical::ArgRough()
{
        return * mArgRough;
}

LArgMain & cCommonAppliTiepHistorical::ArgDSM_Equalization()
{
        return * mArgDSM_Equalization;
}

LArgMain & cCommonAppliTiepHistorical::ArgSuperGlue()
{
        return * mArgSuperGlue;
}

LArgMain & cCommonAppliTiepHistorical::ArgMergeTiePt()
{
        return * mArgMergeTiePt;
}

LArgMain & cCommonAppliTiepHistorical::ArgGetPatchPair()
{
        return * mArgGetPatchPair;
}

LArgMain & cCommonAppliTiepHistorical::ArgGetOverlappedImages()
{
        return * mArgGetOverlappedImages;
}

LArgMain & cCommonAppliTiepHistorical::Arg2DRANSAC()
{
        return * mArg2DRANSAC;
}

LArgMain & cCommonAppliTiepHistorical::Arg3DRANSAC()
{
        return * mArg3DRANSAC;
}

LArgMain & cCommonAppliTiepHistorical::ArgGuidedSIFT()
{
        return * mArgGuidedSIFT;
}

LArgMain & cCommonAppliTiepHistorical::ArgCrossCorrelation()
{
        return * mArgCrossCorrelation;
}

LArgMain & cCommonAppliTiepHistorical::ArgCreateGCPs()
{
        return * mArgCreateGCPs;
}

std::string cCommonAppliTiepHistorical::ComParamDSM_Equalization()
{
    std::string aCom = "";
    if (EAMIsInit(&mDir))    aCom += " Dir=" + mDir;
    if (EAMIsInit(&mSTDRange))  aCom +=  " STDRange=" + ToString(mSTDRange);

    return aCom;
}

std::string cCommonAppliTiepHistorical::ComParamGetPatchPair()
{
    std::string aCom = "";
    if (EAMIsInit(&mDir))  aCom +=  " Dir=" + mDir;
    //if (EAMIsInit(&mPatchSz))    aCom += " PatchSz=[" + ToString(mPatchSz.x) + "," + ToString(mPatchSz.y) + "]";
    //if (EAMIsInit(&mBufferSz))    aCom += " BufferSz=[" + ToString(mBufferSz.x) + "," + ToString(mBufferSz.y) + "]";
    if (EAMIsInit(&mSubPatchXml))  aCom +=  " SubPXml=" + mSubPatchXml;
    //if (EAMIsInit(&mOutDir))    aCom +=  " PatchOutDir=" + mOutDir;
    if (EAMIsInit(&mImgPair))  aCom +=  " ImgPair=" + mImgPair;

    return aCom;
}

std::string cCommonAppliTiepHistorical::ComParamSuperGlue()
{
    std::string aCom ="";
    if (EAMIsInit(&mInput_dir))   aCom +=  " InDir=" + mDir + "/" + mInput_dir;
    //if (EAMIsInit(&mOutput_dir))   aCom +=  " SpGOutDir=" + mDir + "/" + mOutput_dir;
    if (EAMIsInit(&mSpGlueOutSH))   aCom +=  " SpGOutSH=" + mSpGlueOutSH;
    if (EAMIsInit(&mResize))    aCom += " Resize=[" + ToString(mResize.x) + "," + ToString(mResize.y) + "]";
    if (EAMIsInit(&mViz))       aCom += " Viz=" + ToString(mViz);
    if (EAMIsInit(&mModel))  aCom +=  " Model=" + mModel;
    if (EAMIsInit(&mMax_keypoints))    aCom +=  " MaxPt=" + ToString(mMax_keypoints);
    if (EAMIsInit(&mKeepNpzFile))   aCom +=  " KeepNpzFile=" + ToString(mKeepNpzFile);
    if (EAMIsInit(&mStrEntSpG))  aCom +=  " EntSpG=" + mStrEntSpG;
    if (EAMIsInit(&mStrOpt))  aCom +=  " opt=\" " + mStrOpt + "\"";

    return aCom;
}

std::string cCommonAppliTiepHistorical::ComParamMergeTiePt()
{
    std::string aCom = "";
    if (EAMIsInit(&mMergeTiePtInSH))   aCom +=  " MergeInSH=" + mMergeTiePtInSH;
    if (EAMIsInit(&mMergeTiePtOutSH))  aCom +=  " MergeOutSH=" + mMergeTiePtOutSH;
    if (EAMIsInit(&mHomoXml))          aCom +=  " HomoXml=" + mHomoXml;

    return aCom;
}

std::string cCommonAppliTiepHistorical::ComParamRANSAC2D()
{
    std::string aCom = "";
    if (EAMIsInit(&mR2DInSH))   aCom +=  " 2DRANInSH=" + mR2DInSH;
    if (EAMIsInit(&mR2DOutSH))  aCom +=  " 2DRANOutSH=" + mR2DOutSH;
    if (EAMIsInit(&mR2DIteration))          aCom +=  " 2DIter=" + ToString(mR2DIteration);
    if (EAMIsInit(&mR2DThreshold))          aCom +=  " 2DRANTh=" + ToString(mR2DThreshold);

    return aCom;
}

std::string cCommonAppliTiepHistorical::ComParamCreateGCPs()
{
    std::string aCom = "";
    if (EAMIsInit(&mCreateGCPsInSH))     aCom +=  " CreateGCPsInSH=" + mCreateGCPsInSH;
    if (EAMIsInit(&mOut2DXml1))          aCom +=  " Out2DXml1=" + mOut2DXml1;
    if (EAMIsInit(&mOut2DXml2))          aCom +=  " Out2DXml2=" + mOut2DXml2;
    if (EAMIsInit(&mOut3DXml1))          aCom +=  " Out3DXml1=" + mOut3DXml1;
    if (EAMIsInit(&mOut3DXml2))          aCom +=  " Out3DXml2=" + mOut3DXml2;

    return aCom;
}

std::string cCommonAppliTiepHistorical::ComParamGuidedSIFTMatch()
{
    std::string aCom = "";
    if (EAMIsInit(&mGuidedSIFTOutSH   ))          aCom +=  " GSIFTOutSH=" + mGuidedSIFTOutSH;
    if (EAMIsInit(&mSkipSIFT   ))          aCom +=  " SkipSIFT=" + ToString(mSkipSIFT);
    if (EAMIsInit(&mSearchSpace   ))          aCom +=  " SearchSpace=" + ToString(mSearchSpace);
    if (EAMIsInit(&mMutualNN   ))          aCom +=  " MutualNN=" + ToString(mMutualNN);
    if (EAMIsInit(&mRatioT   ))          aCom +=  " RatioT=" + ToString(mRatioT);
    if (EAMIsInit(&mRootSift   ))          aCom +=  " RootSift=" + ToString(mRootSift);
    if (EAMIsInit(&mCheckScale   ))          aCom +=  " CheckScale=" + ToString(mCheckScale);
    if (EAMIsInit(&mCheckAngle   ))          aCom +=  " CheckAngle=" + ToString(mCheckAngle);
    if (EAMIsInit(&mPredict   ))          aCom +=  " Predict=" + ToString(mPredict);
    if (EAMIsInit(&mScale   ))          aCom +=  " Scale=" + ToString(mScale);
    if (EAMIsInit(&mAngle ))          aCom +=  " Angle=" + ToString(mAngle);

    return aCom;
}

std::string cCommonAppliTiepHistorical::ComParamGetOverlappedImages()
{
    std::string aCom = "";
    if (EAMIsInit(&mOutPairXml))          aCom +=  " OutPairXml=" + mOutPairXml;

    return aCom;
}

std::string cCommonAppliTiepHistorical::GetFolderName(std::string strIn)
{
    std::string strOut = strIn;

    std::size_t found = strIn.find("/");
    if (found!=std::string::npos)
        strOut = strIn.substr(0, found);

    return strOut;
}

/*******************************************/
/****** cAppliTiepHistoricalPipeline  ******/
/*******************************************/

std::string cAppliTiepHistoricalPipeline::StdCom(const std::string & aCom,const std::string & aPost, bool aExe)
{
    std::string  aFullCom = MMBinFile(MM3DStr) +  aCom + BLANK;
    aFullCom = aFullCom + aPost;
/*
    if(aExe == false)
    {
        std::cout << "COM= " << aFullCom << "\n";
        return aFullCom;
    }
*/
    if (aExe)
    {
       //std::cout << "---------->>>>  " << aFullCom << "\n";
       System(aFullCom);
    }
    else
       std::cout << aFullCom << "\n";

    return aFullCom;

    //std::cout << " DONE " << aCom << " in time " << mChrono.uval() << "\n";
}

std::string cAppliTiepHistoricalPipeline::GetImage_Profondeur(std::string aDSMDir, std::string aDSMFile)
{
    cXML_ParamNuage3DMaille aNuageIn = StdGetObjFromFile<cXML_ParamNuage3DMaille>
    (
    aDSMDir + "/" + aDSMFile,
    StdGetFileXMLSpec("SuperposImage.xml"),
    "XML_ParamNuage3DMaille",
    "XML_ParamNuage3DMaille"
    );


    cImage_Profondeur aImDSM = aNuageIn.Image_Profondeur().Val();
    return aImDSM.Image();
}

int cAppliTiepHistoricalPipeline::GetTiePtNum(std::string aDir, std::string aImg1, std::string aImg2, std::string aSH)
{
    std::string aDir_inSH = aDir + "/Homol" + aSH+"/";
    std::string aNameIn = aDir_inSH +"Pastis" + aImg1 + "/"+aImg2+".txt";

    if (ELISE_fp::exist_file(aNameIn) == false)
    {
        cout<<aNameIn<<"didn't exist hence skipped."<<endl;
        return 0;
    }
    ElPackHomologue aPackFull =  ElPackHomologue::FromFile(aNameIn);

    //    int nPtNum = int(aPackFull.end() - aPackFull.begin());
    int nPtNum = 0;
    for (ElPackHomologue::iterator itCpl=aPackFull.begin(); itCpl!=aPackFull.end(); itCpl++)
    {
        nPtNum++;
    }

    return nPtNum;
}

int cAppliTiepHistoricalPipeline::GetOverlappedImgPair(std::string aName, std::vector<std::string>& aResL, std::vector<std::string>& aResR)
{
    //std::vector<tNamePair> aRes;
    int num = 0;
    cSauvegardeNamedRel aSNR = StdGetFromPCP(aName,SauvegardeNamedRel);
    for (const auto & aCpl : aSNR.Cple())
    {
        aResL.push_back(aCpl.N1());
        aResR.push_back(aCpl.N2());
        num++;
        //aRes.Add(tNamePair(aCpl.N1(),aCpl.N2()));
    }

    return num;
}

std::string cAppliTiepHistoricalPipeline::GetImgList(std::string aDir, std::string aFileName, bool bExe)
{
    std::string aRes;

    std::vector<std::string> aVIm;
    bool bTxt = GetImgListVec(aFileName, aVIm, bExe);
    if(bTxt == true)
    {
        aRes = "\"";
        for(int i=0; i<int(aVIm.size()); i++)
        {
            aRes += aVIm[i]+"|";
        }
        aRes = aRes.substr(0, aRes.length()-1) + "\"";
    }
    else
        aRes = aFileName;


    return aRes;
}

void cAppliTiepHistoricalPipeline::DoAll()
{
    std::string aCom;

    std::string aBaseOutDir = "./Tmp_Patches";
    if(aBaseOutDir.find("/") == aBaseOutDir.length()-1)
        aBaseOutDir = aBaseOutDir.substr(0, aBaseOutDir.length()-1);
    std::string aOutDir = aBaseOutDir;

    std::string aOri1 = mOri1;
    StdCorrecNameOrient(aOri1,"./",true);
    std::string aOri2 = mOri2;
    StdCorrecNameOrient(aOri2,"./",true);

    if(mSkipCoReg == false)
    {
        printf("**************************************1- rough co-registration************************************\n");
        /********************1- rough co-registration******************/

        aOutDir = aBaseOutDir + "-CoReg";

        std::string aDSMImgNameL = GetImage_Profondeur(mCAS3D.mDir+mDSMDirL, mDSMFileL);
        std::string aDSMImgNameR = GetImage_Profondeur(mCAS3D.mDir+mDSMDirR, mDSMFileR);
        std::string aDSMImgGrayNameL = StdPrefix(aDSMImgNameL)+"_gray."+StdPostfix(aDSMImgNameL);
        std::string aDSMImgGrayNameR = StdPrefix(aDSMImgNameR)+"_gray."+StdPostfix(aDSMImgNameR);

        /**************************************/
        /* 1.1 - DSM_Equalization and wallis filter */
        /**************************************/
        StdCom("TestLib DSM_Equalization", mDSMDirL + BLANK + "DSMFile="+mDSMFileL + BLANK
                                                                    + mCAS3D.ComParamDSM_Equalization(), mExe);
        StdCom("TestLib DSM_Equalization", mDSMDirR + BLANK + "DSMFile="+mDSMFileR + BLANK
                                                                    + mCAS3D.ComParamDSM_Equalization(), mExe);

        StdCom("TestLib Wallis", aDSMImgGrayNameL + BLANK + "Dir="+mDSMDirL, mExe);
        StdCom("TestLib Wallis", aDSMImgGrayNameR + BLANK + "Dir="+mDSMDirR, mExe);

        /**************************************/
        /* 1.2 - GetPatchPair for rough co-registration */
        /**************************************/
        std::string aDSMImgWallisNameL = aDSMImgGrayNameL+"_sfs.tif";
        std::string aDSMImgWallisNameR = aDSMImgGrayNameR+"_sfs.tif";
        aCom = "";
        //if (!EAMIsInit(&mCAS3D.mOutDir))   aCom +=  " OutDir=" + aOutDir;
        if (EAMIsInit(&mCoRegPatchSz))  aCom += " PatchSz=[" + ToString(mCoRegPatchSz.x) + "," + ToString(mCoRegPatchSz.y) + "]";
        aCom += " BufferSz=[" + ToString(mCoRegBufferSz.x) + "," + ToString(mCoRegBufferSz.y) + "]";
        StdCom("TestLib GetPatchPair BruteForce", mDSMDirL+"/"+aDSMImgWallisNameL + BLANK + mDSMDirR+"/"+aDSMImgWallisNameR + BLANK + aCom + BLANK + "Rotate=1" + BLANK + mCAS3D.ComParamGetPatchPair(), mExe);

        std::string aDSMImgGrayNameRenamedL = mCAS3D.GetFolderName(mDSMDirL) + "." + StdPostfix(aDSMImgNameL);
        std::string aDSMImgGrayNameRenamedR = mCAS3D.GetFolderName(mDSMDirR) + "." + StdPostfix(aDSMImgNameR);

        std::string aRotate[4] = {"", "_R90", "_R180", "_R270"};
        std::string aFinalOutSH;
        int nMaxinlier = 0;
        //Rotate the master DSM 4 times and apply superGlue
        for(int i=0; i<4; i++)
        {
            if(mRotateDSM != -1)
            {
                std::string aRotateDSMStr = "_R" + ToString(mRotateDSM);
                if(mRotateDSM == 0)
                    aRotateDSMStr = "";
                if(aRotate[i] != aRotateDSMStr)
                {
                    printf("%dth attempt with \"%s\" doesn't match with \"%s\", hence skipped\n", i, aRotate[i].c_str(), aRotateDSMStr.c_str());
                    continue;
                }
            }
            /**************************************/
            /* 1.3 - SuperGlue for rough co-registration */
            /**************************************/
            std::string aImgPair = StdPrefix(mCAS3D.mImgPair) + aRotate[i] + "." + StdPostfix(mCAS3D.mImgPair);
            aCom = "";
            if (!EAMIsInit(&mCAS3D.mInput_dir))    aCom +=  " InDir=" + aOutDir+"/";
            //if (!EAMIsInit(&mCAS3D.mOutput_dir))   aCom +=  " SpGOutDir=" + aOutDir+"/";
            aCom +=  " CheckNb=\" " + ToString(mCheckNbCoReg) + "\"";
            StdCom("TestLib SuperGlue", aImgPair + BLANK + aCom + BLANK + mCAS3D.ComParamSuperGlue(), mExe);


            /**************************************/
            /* 1.4 - MergeTiePt for rough co-registration */
            /**************************************/
            std::string aHomoXml = StdPrefix(mCAS3D.mHomoXml) + aRotate[i] + "." + StdPostfix(mCAS3D.mHomoXml);
            aCom = "";
            if (!EAMIsInit(&mCAS3D.mHomoXml))   aCom +=  " HomoXml=" + aHomoXml;
            if (!EAMIsInit(&mCAS3D.mMergeTiePtInSH))   aCom +=  " MergeInSH=" + mCAS3D.mSpGlueOutSH;
            aCom +=  " PatchSz=[" + ToString(mCoRegPatchSz.x) + "," + ToString(mCoRegPatchSz.y) + "]";
            aCom +=  " BufferSz=[" + ToString(mCoRegBufferSz.x) + "," + ToString(mCoRegBufferSz.y) + "]";
            StdCom("TestLib MergeTiePt", aOutDir+"/" + BLANK + aCom + BLANK + mCAS3D.ComParamMergeTiePt(), mExe);


            /**************************************/
            /* 1.5 - RANSAC R2D for rough co-registration */
            /**************************************/
            aCom = "";
            if (!EAMIsInit(&mCAS3D.mR2DInSH))   aCom +=  " 2DRANInSH=-" + StdPrefix(aHomoXml);
            std::string aRANSACOutSH = "-" + StdPrefix(aHomoXml) + "-2DRANSAC";
            StdCom("TestLib RANSAC R2D", aDSMImgGrayNameRenamedL + BLANK + aDSMImgGrayNameRenamedR + BLANK + "Dir=" + aOutDir+"/" + BLANK + aCom + BLANK + mCAS3D.ComParamRANSAC2D(), mExe);
            int nInlier = GetTiePtNum(aOutDir, aDSMImgGrayNameRenamedL, aDSMImgGrayNameRenamedR, aRANSACOutSH);
            cout<<i<<",,"<<aRANSACOutSH<<","<<nInlier<<endl;

            if(nInlier > nMaxinlier)
            {
                nMaxinlier = nInlier;
                aFinalOutSH = aRANSACOutSH;
            }
        }
        cout<<"aFinalOutSH: "<<aFinalOutSH<<endl;


        /**************************************/
        /* 1.6 - CreateGCPs for rough co-registration */
        /**************************************/
        aCom = "";
        if (!EAMIsInit(&mCAS3D.mCreateGCPsInSH))   aCom +=  " CreateGCPsInSH=" + aFinalOutSH;
        StdCom("TestLib CreateGCPs", aOutDir + BLANK + aDSMImgGrayNameRenamedL + BLANK + aDSMImgGrayNameRenamedR + BLANK + mCAS3D.mDir + BLANK + mImgList1 + BLANK + mImgList2 + BLANK + mOri1 + BLANK + mOri2 + BLANK + mDSMDirL + BLANK + mDSMDirR + aCom + mCAS3D.ComParamCreateGCPs(), mExe);


        /**************************************/
        /* 1.7 - GCPBascule for rough co-registration */
        /**************************************/
        aCom = "";
        std::string aImgListL = GetImgList(mCAS3D.mDir, mImgList1, mExe);
        StdCom("GCPBascule", aImgListL + BLANK + mOri1 + BLANK + mCoRegOri.substr(4,mCoRegOri.length()) + BLANK + mCAS3D.mOut3DXml2 + BLANK + mCAS3D.mOut2DXml1, mExe);
        /*
        aCom = "/home/lulin/Documents/ThirdParty/oldMicmac/micmac_old/bin/mm3d GCPBascule " + aImgListL + BLANK + mOri1 + BLANK + mCoRegOri.substr(4,mCoRegOri.length()) + BLANK + mCAS3D.mOut3DXml2 + BLANK + mCAS3D.mOut2DXml1;
        if(mExe==true)
            System(aCom);
        cout<<aCom<<endl;
        */
    }


    if(mSkipPrecise == false)
    {
        printf("**************************************2- precise matching************************************\n");
    /********************2- precise matching******************/
    aOutDir = aBaseOutDir + "-Precise";

    /**************************************/
    /* 2.1 - GetOverlappedImages */
    /**************************************/
    StdCom("TestLib GetOverlappedImages", mOri1 + BLANK + mOri2 + BLANK + mImg4MatchList1 + BLANK + mImg4MatchList2 + BLANK + mCAS3D.ComParamGetOverlappedImages() + BLANK + "Para3DH=Basc-"+aOri1+"-2-"+aOri2+".xml", mExe);

    if (ELISE_fp::exist_file(mCAS3D.mOutPairXml) == false)
    {
        cout<<mCAS3D.mOutPairXml<<" didn't exist because the pipeline is not executed, hence the precise matching commands are not shown here."<<endl;
        return;
    }

    bool aExe = false;
    std::vector<std::string> aOverlappedImgL;
    std::vector<std::string> aOverlappedImgR;
    int nPairNum = GetOverlappedImgPair(mCAS3D.mOutPairXml, aOverlappedImgL, aOverlappedImgR);

    std::list<std::string> aComList;
    std::string aComSingle;
    /**************************************/
    /* 2.2 - GetPatchPair for precise matching */
    /**************************************/
    cout<<"-------GetPatchPair-------"<<endl;
    //if(mSkipGetPatchPair == false)
    {
    for(int i=0; i<nPairNum; i++)
    {
        std::string aImg1 = aOverlappedImgL[i];
        std::string aImg2 = aOverlappedImgR[i];
/*
        cout<<"---------------------"<<i<<"th pair------------------"<<endl;
        cout<<aImg1<<" "<<aImg2<<endl;
*/
        std::string aPrefix = StdPrefix(aImg1) + "_" + StdPrefix(aImg2) + "_" ;
        aCom = "";
        //if (!EAMIsInit(&mCAS3D.mOutDir))   aCom +=  " OutDir=" + aOutDir;
        if (!EAMIsInit(&mCAS3D.mSubPatchXml))  aCom +=  " SubPXml=" + aPrefix + mCAS3D.mSubPatchXml;
        if (!EAMIsInit(&mCAS3D.mImgPair))  aCom +=  " ImgPair=" + aPrefix + mCAS3D.mImgPair;
        if (EAMIsInit(&mPrecisePatchSz))  aCom += " PatchSz=[" + ToString(mPrecisePatchSz.x) + "," + ToString(mPrecisePatchSz.y) + "]";
        if (EAMIsInit(&mDyn))  aCom += " Dyn=" + ToString(mDyn);
        aCom += " BufferSz=[" + ToString(mPreciseBufferSz.x) + "," + ToString(mPreciseBufferSz.y) + "]";
        //aComSingle = StdCom("TestLib GetPatchPair Guided", aImg1 + BLANK + aImg2 + BLANK + mCoRegOri + BLANK + mCoRegOri + BLANK + aCom + BLANK + mCAS3D.ComParamGetPatchPair(), aExe);
        //printf("%s\t%s\n", aOri1.c_str(), mOri1.c_str());
        aComSingle = StdCom("TestLib GetPatchPair Guided", aImg1 + BLANK + aImg2 + BLANK + mOri1 + BLANK + mOri2 + BLANK + aCom + BLANK + mCAS3D.ComParamGetPatchPair() + BLANK + "Para3DH=Basc-"+aOri1+"-2-"+aOri2+".xml" + BLANK + "DSMDirL="+mDSMDirL, aExe);
        aComList.push_back(aComSingle);

        if(mUseDepth == true)
        {
            aComSingle = StdCom("TestLib GetPatchPair Guided", aImg1 + BLANK + aImg2 + BLANK + mOri1 + BLANK + mOri2 + BLANK + aCom + BLANK + mCAS3D.ComParamGetPatchPair() + BLANK + "Para3DH=Basc-"+aOri1+"-2-"+aOri2+".xml" + BLANK + "DSMDirL="+mDSMDirL + BLANK + "Prefix=Depth_", aExe);
            aComList.push_back(aComSingle);
        }
    }
    /*
    for(list<std::string>::iterator it=aComList.begin();it!=aComList.end();it++)
    {
        cout<<(*it)<<endl;
    }
    */
    if(mExe && (!mSkipGetPatchPair))
        //cEl_GPAO::DoComInParal(aComList);
        //because "mm3d TestLib GetPatchPair Guided" is parallized itself, if DoComInParal here, terminal will show "make[1]: warning: -jN forced in submake: disabling jobserver mode."
        cEl_GPAO::DoComInSerie(aComList);
    }

    std::string aRANSACInSH;
    std::string aCrossCorrInSH;
    std::string aCrossCorrOutSH;

    //if(mSkipTentativeMatch == false)
    {
    /**************************************/
    /* 2.3: option 1 - SuperGlue for precise matching */
    /**************************************/
    aComList.clear();
    if(mFeature == "SuperGlue")
    {
        cout<<"-------SuperGlue-------"<<endl;
        for(int i=0; i<nPairNum; i++)
        {
            std::string aImg1 = aOverlappedImgL[i];
            std::string aImg2 = aOverlappedImgR[i];

            std::string aPrefix = StdPrefix(aImg1) + "_" + StdPrefix(aImg2) + "_" ;

            /**************************************/
            /* SuperGlue */
            /**************************************/
            std::string aImgPair = aPrefix + mCAS3D.mImgPair;
            aCom = "";
            if (!EAMIsInit(&mCAS3D.mInput_dir))    aCom +=  " InDir=" + aOutDir+"/";
            //if (!EAMIsInit(&mCAS3D.mOutput_dir))   aCom +=  " SpGOutDir=" + aOutDir+"/";
            aCom +=  "  CheckFile=" + ToString(mCheckFile);
            aCom +=  " CheckNb=\" " + ToString(mCheckNbPrecise) + "\"";
            aComSingle = StdCom("TestLib SuperGlue", aImgPair + BLANK + aCom + BLANK + mCAS3D.ComParamSuperGlue(), aExe);
            aComList.push_back(aComSingle);
        }
        /*
        for(list<std::string>::iterator it=aComList.begin();it!=aComList.end();it++)
        {
            cout<<(*it)<<endl;
        }
        */
        if(mExe && (!mSkipTentativeMatch))
        {
            //cEl_GPAO::DoComInParal(aComList);
            cEl_GPAO::DoComInSerie(aComList);
        }
        aComList.clear();
        cout<<"-------MergeTiePt-------"<<endl;
        for(int i=0; i<nPairNum; i++)
        {
            std::string aImg1 = aOverlappedImgL[i];
            std::string aImg2 = aOverlappedImgR[i];

            std::string aPrefix = StdPrefix(aImg1) + "_" + StdPrefix(aImg2) + "_" ;

            /**************************************/
            /* MergeTiePt  */
            /**************************************/
            std::string aHomoXml = aPrefix + mCAS3D.mHomoXml;
            aCom = "";
            if (!EAMIsInit(&mCAS3D.mHomoXml))   aCom +=  " HomoXml=" + aHomoXml;
            if (!EAMIsInit(&mCAS3D.mMergeTiePtInSH))   aCom +=  " MergeInSH=" + mCAS3D.mSpGlueOutSH;
            if (!EAMIsInit(&mCAS3D.mMergeTiePtOutSH))
            {
                aCom +=  " MergeOutSH="+mCAS3D.mSpGlueOutSH;
                aRANSACInSH = mCAS3D.mSpGlueOutSH;
            }
            else
                aRANSACInSH = mCAS3D.mMergeTiePtOutSH;
            aCom +=  " PatchSz=[" + ToString(mPrecisePatchSz.x) + "," + ToString(mPrecisePatchSz.y) + "]";
            aCom +=  " BufferSz=[" + ToString(mPreciseBufferSz.x) + "," + ToString(mPreciseBufferSz.y) + "]";
            aComSingle = StdCom("TestLib MergeTiePt", aOutDir+"/" + BLANK + aCom + BLANK + "OutDir=" + mCAS3D.mDir + BLANK + mCAS3D.ComParamMergeTiePt(), aExe);
            aComList.push_back(aComSingle);
        }
        /*
        for(list<std::string>::iterator it=aComList.begin();it!=aComList.end();it++)
        {
            cout<<(*it)<<endl;
        }
        */
        if(mExe && (!mSkipTentativeMatch))
            cEl_GPAO::DoComInParal(aComList);
    }
    /**************************************/
    /* 2.3: option 2 - Guided SIFT for precise matching */
    /**************************************/
    else if(mFeature == "SIFT")
    {
        cout<<"-------Guided SIFT-------"<<endl;
        // Extract SIFT if SkipSIFT is set to false
        if(mExe == true && (!mSkipTentativeMatch) && mCAS3D.mSkipSIFT == false)
        {
            std::vector<std::string> aVIm1;
            std::vector<std::string> aVIm2;
            GetImgListVec(mCAS3D.mDir+mImg4MatchList1, aVIm1, mExe);
            GetImgListVec(mCAS3D.mDir+mImg4MatchList2, aVIm2, mExe);
            for(unsigned int k=0; k<aVIm1.size(); k++)
                ExtractSIFT(aVIm1[k], mCAS3D.mDir, mScaleL);
            for(unsigned int k=0; k<aVIm2.size(); k++)
                ExtractSIFT(aVIm2[k], mCAS3D.mDir, mScaleR);
        }

        for(int i=0; i<nPairNum; i++)
        {
            std::string aImg1 = aOverlappedImgL[i];
            std::string aImg2 = aOverlappedImgR[i];

            aCom = "";
            aCom +=  " SkipSIFT=true";
            aCom +=  " DSMDirL=" + mDSMDirL;
            aCom +=  " DSMDirR=" + mDSMDirR;
            if (EAMIsInit(&mDSMFileL))   aCom +=  " DSMFileL=" + mDSMFileL;
            if (EAMIsInit(&mDSMFileR))   aCom +=  " DSMFileR=" + mDSMFileR;
            if (EAMIsInit(&mScaleL))   aCom +=  " ScaleL=" + ToString(mScaleL);
            if (EAMIsInit(&mScaleR))   aCom +=  " ScaleR=" + ToString(mScaleR);
            aCom +=  "  CheckFile=" + ToString(mCheckFile);
            aComSingle = StdCom("TestLib GuidedSIFTMatch", aImg1 + BLANK + aImg2 + BLANK + mOri1 + BLANK + mOri2 + BLANK + aCom + BLANK + mCAS3D.ComParamGuidedSIFTMatch() + BLANK + "Para3DHL=Basc-"+aOri1+"-2-"+aOri2+".xml" + BLANK + "Para3DHR=Basc-"+aOri2+"-2-"+aOri1+".xml", aExe);

            aRANSACInSH = mCAS3D.mGuidedSIFTOutSH;
            aComList.push_back(aComSingle);
        }
        /*
        for(list<std::string>::iterator it=aComList.begin();it!=aComList.end();it++)
        {
            cout<<(*it)<<endl;
        }
        */
        if(mExe && (!mSkipTentativeMatch))
            cEl_GPAO::DoComInParal(aComList);
    }
    else
    {
        cout<<"Please set Feature to SuperGlue or SIFT"<<endl;
        return;
    }
    //cout<<"aRANSACInSH: "<<aRANSACInSH<<endl;
    }

    /**************************************/
    /* 2.4 - RANSAC R3D for precise matching */
    /**************************************/
    //if(mSkipRANSAC3D == false)
    {
        cout<<"-------RANSAC R3D-------"<<endl;
    aComList.clear();
    for(int i=0; i<nPairNum; i++)
    {
        std::string aImg1 = aOverlappedImgL[i];
        std::string aImg2 = aOverlappedImgR[i];

        aCom = "";
        aCom +=  " DSMDirL=" + mDSMDirL;
        aCom +=  " DSMDirR=" + mDSMDirR;
        if (EAMIsInit(&mDSMFileL))   aCom +=  " DSMFileL=" + mDSMFileL;
        if (EAMIsInit(&mDSMFileR))   aCom +=  " DSMFileR=" + mDSMFileR;
        if (EAMIsInit(&mCAS3D.mR3DInSH))
            aRANSACInSH = mCAS3D.mR3DInSH;
        if (EAMIsInit(&mCAS3D.mR3DOutSH))
            aCrossCorrInSH = mCAS3D.mR3DOutSH;
        else
            aCrossCorrInSH = aRANSACInSH+"-3DRANSAC";
        aCom +=  " 3DRANInSH=" + aRANSACInSH;
        aCom +=  " 3DRANOutSH=" + aCrossCorrInSH;
        /*
        if (!EAMIsInit(&mCAS3D.mR3DInSH)){
            aCom +=  " 3DRANInSH=" + aRANSACInSH;
            aCrossCorrInSH = aRANSACInSH+"-3DRANSAC";
        }
        else                                    aCom += " 3DRANInSH=" + mCAS3D.mR3DInSH;
        if (!EAMIsInit(&mCAS3D.mR3DOutSH))   aCom +=  " 3DRANOutSH=" + aCrossCorrInSH;
        else                                    aCom += " 3DRANOutSH=" + mCAS3D.mR3DOutSH;
        */
        if (EAMIsInit(&mCAS3D.mR3DIteration))   aCom +=  " 3DIter=" + ToString(mCAS3D.mR3DIteration);
        if (EAMIsInit(&mCAS3D.mR3DThreshold))   aCom +=  " 3DRANTh=" + ToString(mCAS3D.mR3DThreshold);
        if (EAMIsInit(&mCAS3D.mMinPt))   aCom +=  " MinPt=" + ToString(mCAS3D.mMinPt);
        //aCom +=  " Para3DHL=Basc-"+aOri1+"-2-"+aOri2+".xml";
        aCom +=  "  CheckFile=" + ToString(mCheckFile);
        aComSingle = StdCom("TestLib RANSAC R3D", aImg1 + BLANK + aImg2 + BLANK + mOri1 + BLANK + mOri2 + BLANK + "Dir=" + mCAS3D.mDir + BLANK + aCom, aExe);
        aComList.push_back(aComSingle);
    }
    /*
    for(list<std::string>::iterator it=aComList.begin();it!=aComList.end();it++)
    {
        cout<<(*it)<<endl;
    }
    */
    if(mExe && (!mSkipRANSAC3D))
        cEl_GPAO::DoComInParal(aComList);
    }

    //if(mSkipCrossCorr == false)
    {
        /**************************************/
        /* 2.5 - CrossCorrelation for precise matching */
        /**************************************/
        cout<<"-------CrossCorrelation-------"<<endl;
    aComList.clear();
    for(int i=0; i<nPairNum; i++)
    {
        std::string aImg1 = aOverlappedImgL[i];
        std::string aImg2 = aOverlappedImgR[i];

        std::string aPrefix = StdPrefix(aImg1) + "_" + StdPrefix(aImg2) + "_" ;

        aCom = "";
        if (EAMIsInit(&mCAS3D.mCrossCorrelationInSH))
            aCrossCorrInSH = mCAS3D.mCrossCorrelationInSH;
        if (EAMIsInit(&mCAS3D.mCrossCorrelationOutSH))
            aCrossCorrOutSH = mCAS3D.mCrossCorrelationOutSH;
        else
            aCrossCorrOutSH = aCrossCorrInSH+"-CrossCorrelation";
        aCom +=  " CCInSH=" + aCrossCorrInSH;
        aCom +=  " CCOutSH=" + aCrossCorrOutSH;
        /*
        if (!EAMIsInit(&mCAS3D.mCrossCorrelationInSH)){
            aCom +=  " CCInSH=" + aRANSACInSH+"-3DRANSAC";
            aCrossCorrOutSH = aRANSACInSH+"-3DRANSAC-CrossCorrelation";
        }
        else                                             aCom +=  " CCInSH=" + mCAS3D.mCrossCorrelationInSH;
        if (!EAMIsInit(&mCAS3D.mCrossCorrelationOutSH))  aCom +=  " CCOutSH=" + aCrossCorrOutSH;
        else                                             aCom +=  " CCOutSH=" + mCAS3D.mCrossCorrelationOutSH;
        */
        aCom +=  " SzW=" + ToString(mCAS3D.mWindowSize);
        aCom +=  " CCTh=" + ToString(mCAS3D.mCrossCorrThreshold);
        if (EAMIsInit(&mPrecisePatchSz))  aCom += " PatchSz=[" + ToString(mPrecisePatchSz.x) + "," + ToString(mPrecisePatchSz.y) + "]";
        aCom += " BufferSz=[" + ToString(mPreciseBufferSz.x) + "," + ToString(mPreciseBufferSz.y) + "]";
        aCom +=  " PatchDir=" + aOutDir;
        aCom +=  " SubPXml=" + aPrefix + mCAS3D.mSubPatchXml;
        //cout<<aCom<<endl;
        aCom +=  "  CheckFile=" + ToString(mCheckFile);
        //cout<<aCom<<endl;
        aComSingle = StdCom("TestLib CrossCorrelation", aImg1 + BLANK + aImg2 + BLANK + aCom, aExe);
        aComList.push_back(aComSingle);
    }
    /*
    for(list<std::string>::iterator it=aComList.begin();it!=aComList.end();it++)
    {
        cout<<(*it)<<endl;
    }
    */
    if(mExe && (!mSkipCrossCorr))
        cEl_GPAO::DoComInParal(aComList);
    }
    }
}

cAppliTiepHistoricalPipeline::cAppliTiepHistoricalPipeline(int argc,char** argv) :
        mDebug(false)

{
    mExe = true;
    mUseDepth = false;
    mDSMFileL = "MMLastNuage.xml";
    mDSMFileR = "MMLastNuage.xml";
    mFeature = "SuperGlue";
    //mCoRegOri = "Co-reg";
    mSkipCoReg = false;
    mSkipPrecise = false;
    mSkipGetPatchPair = false;
    mSkipTentativeMatch = false;
    mSkipRANSAC3D = false;
    mSkipCrossCorr = false;
    mRotateDSM = -1;
    mCheckFile = false;
    mImg4MatchList1 = "";
    mImg4MatchList2 = "";
    mCoRegPatchSz = Pt2dr(640, 480);
    mCoRegBufferSz = Pt2dr(0, 0);

    mPrecisePatchSz = Pt2dr(640, 480);
    mPreciseBufferSz = Pt2dr(-1, -1);

    mCheckNbCoReg = -1;
    mCheckNbPrecise = 100;

    mDyn = 0.1;
    mScaleL = 1;
    mScaleR = 1;

   ElInitArgMain
   (
        argc,argv,
        LArgMain()
               << EAMC(mOri1,"Orientation of epoch1")
               << EAMC(mOri2,"Orientation of epoch2")
               << EAMC(mImgList1,"ImgList1: All RGB images in epoch1 (Dir+Pattern, or txt file of image list)")
               << EAMC(mImgList2,"ImgList2: All RGB images in epoch2 (Dir+Pattern, or txt file of image list)")
               << EAMC(mDSMDirL, "DSM directory of epoch1")
               << EAMC(mDSMDirR, "DSM directory of epoch2"),

        LArgMain()
               << EAM(mExe,"Exe",true,"Execute all, Def=true. If this parameter is set to false, the pipeline will not be executed and the command of all the submodules will be printed.")
               << EAM(mImg4MatchList1,"IL1",true,"RGB images in epoch1 for extracting inter-epoch correspondences (Dir+Pattern, or txt file of image list), Def=ImgList1")
               << EAM(mImg4MatchList2,"IL2",true,"RGB images in epoch2 for extracting inter-epoch correspondences (Dir+Pattern, or txt file of image list), Def=ImgList2")
               << EAM(mCheckFile, "CheckFile", true, "Check if the result files of inter-epoch correspondences exist (if so, skip to avoid repetition), Def=false")
               << EAM(mUseDepth,"UseDep",true,"GetPatchPair for depth maps as well (this option is only used for developper), Def=false")
               << EAM(mRotateDSM,"RotateDSM",true,"The angle of rotation from the master DSM to the secondary DSM for rough co-registration (only 4 options available: 0, 90, 180, 270, as the rough co-registration method is invariant to rotation smaller than 45 degree.), Def=-1 (means all the 4 options will be executed, and the one with the most inlier will be kept) ")
               << EAM(mSkipCoReg, "SkipCoReg", true, "Skip the step of rough co-registration, when the input orientations of epoch1 and epoch 2 are already co-registrated, Def=false")
               << EAM(mSkipPrecise, "SkipPrecise", true, "Skip the step of the whole precise matching pipeline, Def=false")
               << EAM(mSkipGetPatchPair, "SkipGetPatchPair", true, "Skip the step of \"GetPatchPair\" in precise matching (this option is used when the results of \"GetPatchPair\" already exist), Def=false")
               << EAM(mSkipTentativeMatch, "SkipTentativeMatch", true, "Skip the step of \"SuperGlue\" or SIFT matching (this option is used when the results of \"SuperGlue\" or SIFT matching already exist), Def=false")
               << EAM(mSkipRANSAC3D, "SkipRANSAC3D", true, "Skip the step of \"3D RANSAC\" (this option is used when the results of \"3D RANSAC\" already exist), Def=false")
               << EAM(mSkipCrossCorr, "SkipCrossCorr", true, "Skip the step of \"cross correlation\" (this option is used when the results of \"cross correlation\" already exist), Def=false")
               << EAM(mFeature,"Feature",true,"Feature matching method used for precise matching (SuperGlue or SIFT), Def=SuperGlue")
               //<< EAM(mCoRegOri,"CoRegOri",true,"Output of Co-registered orientation, Def=Co-reg")
               //<< mCAS3D.ArgBasic()
               << EAM(mDSMFileL, "DSMFileL", true, "DSM File of epoch1, Def=MMLastNuage.xml")
               << EAM(mDSMFileR, "DSMFileR", true, "DSM File of epoch2, Def=MMLastNuage.xml")
               << EAM(mCoRegPatchSz, "CoRegPatchSz", true, "Patch size of the tiling scheme in rough co-registration part, which means the images to be matched by SuperGlue will be split into patches of this size, Def=[640, 480]")
               << EAM(mCoRegBufferSz, "CoRegBufferSz", true, "Buffer zone size around the patch of the tiling scheme in rough co-registration part, Def=[0, 0]")
               << EAM(mPrecisePatchSz, "PrecisePatchSz", true, "Patch size of the tiling scheme in precise matching part, which means the images to be matched by SuperGlue will be split into patches of this size, Def=[640, 480]")
               << EAM(mPreciseBufferSz, "PreciseBufferSz", true, "Buffer zone size around the patch of the tiling scheme in precise matching part, Def=10%*PrecisePatchSz")
               << mCAS3D.ArgDSM_Equalization()
               << mCAS3D.ArgGetPatchPair()
               << EAM(mDyn, "Dyn", true, "The Dyn parameter in \"to8Bits\" if the input RGB images are 16 bits, Def=0.1")
               << mCAS3D.ArgSuperGlue()
               << EAM(mCheckNbCoReg,"CheckNbCoReg",true,"Radius of the search space for SuperGlue in rough co-registration step (which means correspondence [(xL, yL), (xR, yR)] with (xL-xR)*(xL-xR)+(yL-yR)*(yL-yR) > CheckNb*CheckNb will be removed afterwards), Def=-1 (means don't check search space)")
               << EAM(mCheckNbPrecise,"CheckNbPrecise",true,"Radius of the search space for SuperGlue in precise matching step (which means correspondence [(xL, yL), (xR, yR)] with (xL-xR)*(xL-xR)+(yL-yR)*(yL-yR) > CheckNb*CheckNb will be removed afterwards), Def=100")
               << mCAS3D.ArgMergeTiePt()
               << mCAS3D.Arg2DRANSAC()
               << mCAS3D.ArgCreateGCPs()
               << mCAS3D.ArgGetOverlappedImages()
               << mCAS3D.ArgGuidedSIFT()
               << EAM(mScaleL, "ScaleL", true, "Extract SIFT points on master images downsampled with a factor of \"ScaleL\", Def=1")
               << EAM(mScaleR, "ScaleR", true, "Extract SIFT points on secondary images downsampled with a factor of \"ScaleR\", Def=1")
               << mCAS3D.Arg3DRANSAC()
               << mCAS3D.ArgCrossCorrelation()
/*
                    << EAM(mDebug, "Debug", true, "Debug mode, def false")
                    << mCAS3D.ArgBasic()
                    << mCAS3D.ArgRough()
*/
               );
   mCoRegOri = mOri2;

   if(mPreciseBufferSz.x < 0 && mPreciseBufferSz.y < 0){
       mPreciseBufferSz.x = int(0.1*mPrecisePatchSz.x);
       mPreciseBufferSz.y = int(0.1*mPrecisePatchSz.y);
   }

   if(mImg4MatchList1.length() == 0)
       mImg4MatchList1 = mImgList1;

   if(mImg4MatchList2.length() == 0)
       mImg4MatchList2 = mImgList2;

   StdCorrecNameOrient(mOri,mCAS3D.mDir,true);
}


/*******************************************/
/****** cTransform3DHelmert  ******/
/*******************************************/

cTransform3DHelmert::cTransform3DHelmert(std::string aFileName)
{
    //if(aFileName.length() == 0)
    if(ELISE_fp::exist_file(aFileName) == false)
    {
        if(aFileName.length() > 0)
            printf("File %s does not exist, hence will use unit matrix instead.\n", aFileName.c_str());
        mApplyTrans = false;
        mScl = 1;
        mTr = Pt3dr(0,0,0);
    }
    else
    {
        mApplyTrans = true;
        mTransf = OptStdGetFromPCP(aFileName, Xml_ParamBascRigide);
        mScl = mTransf->Scale();
        mTr = mTransf->Trans();
        //mRot = mTransf->ParamRotation();
    }
}

bool cTransform3DHelmert::GetApplyTrans()
{
    return mApplyTrans;
}

double cTransform3DHelmert::GetScale()
{
    return mScl;
}

Pt3dr cTransform3DHelmert::Transform3Dcoor(Pt3dr aPt)
{
    if(mApplyTrans == false)
        return aPt;
    else
    {
        Pt3dr aPtBasc(
                    scal(mTransf->ParamRotation().L1() , aPt) * mScl + mTr.x,
                    scal(mTransf->ParamRotation().L2() , aPt) * mScl + mTr.y,
                    scal(mTransf->ParamRotation().L3() , aPt) * mScl + mTr.z
                     );

        return aPtBasc;
    }
}

/*******************************************/
/****** cDSMInfo  ******/
/*******************************************/

cDSMInfo::cDSMInfo(Pt2di aDSMSz, std::string aDSMFile, std::string aDSMDir) :
mTImDSM  (aDSMSz),
mTImMask (aDSMSz)
{
    mDSMSz = aDSMSz;
    bDSM = true;

    if(true)
    {
        aDSMDir += "/";

        if (ELISE_fp::exist_file(aDSMDir + aDSMFile) == false)
        {
            printf("%s didn't exist\n", (aDSMDir + aDSMFile).c_str());
            bDSM = false;
        }
        else
        {
            cXML_ParamNuage3DMaille aNuageIn = StdGetObjFromFile<cXML_ParamNuage3DMaille>
            (
            aDSMDir + aDSMFile,
            StdGetFileXMLSpec("SuperposImage.xml"),
            "XML_ParamNuage3DMaille",
            "XML_ParamNuage3DMaille"
            );

            mDSMSz = aNuageIn.NbPixel();

            cImage_Profondeur aImDSM = aNuageIn.Image_Profondeur().Val();

            mDSMName = aImDSM.Image();
            std::string aDSMFullName = aDSMDir + mDSMName;
            Tiff_Im aImDSMTif(aDSMFullName.c_str());
            ELISE_COPY
            (
            mTImDSM.all_pts(),
            aImDSMTif.in(),
            mTImDSM.out()
            );

            mMaskName = aImDSM.Masq();
            std::string aMaskFullName = aDSMDir + mMaskName;
            Tiff_Im aImMaskTif(aMaskFullName.c_str());
            ELISE_COPY
            (
            mTImMask.all_pts(),
            aImMaskTif.in(),
            mTImMask.out()
            );

            mFOM = StdGetFromPCP(aDSMDir+StdPrefix(mDSMName)+".xml",FileOriMnt);

            mOriPlani = mFOM.OriginePlani();
            mResolPlani = mFOM.ResolutionPlani();
        }
    }
}

double cDSMInfo::GetDSMValue(Pt2di aPt2)
{
    if(bDSM == false)
        return 0;

    return mTImDSM.get(aPt2);
}

double cDSMInfo::GetMasqValue(Pt2di aPt2)
{
    if(bDSM == false)
        return 0;

    return mTImMask.get(aPt2);
}

//get 2d coordinate in DSM
Pt2dr cDSMInfo::Get2DcoorInDSM(Pt3dr aTer)
{
    if(bDSM == false)
        return Pt2dr(0,0);

    Pt2dr aPt2;
    aPt2.x = (aTer.x - mOriPlani.x)/mResolPlani.x + 0.5;
    aPt2.y = (aTer.y - mOriPlani.y)/mResolPlani.y + 0.5;

    return aPt2;
}

Pt2di cDSMInfo::GetDSMSz(std::string aDSMFile, std::string aDSMDir)
{
    if(aDSMDir.length() == 0)
        return Pt2di(0,0);
    aDSMDir += "/";

    cXML_ParamNuage3DMaille aNuageIn = StdGetObjFromFile<cXML_ParamNuage3DMaille>
    (
    aDSMDir + aDSMFile,
    StdGetFileXMLSpec("SuperposImage.xml"),
    "XML_ParamNuage3DMaille",
    "XML_ParamNuage3DMaille"
    );

    return aNuageIn.NbPixel();
}

std::string cDSMInfo::GetDSMName(std::string aDSMFile, std::string aDSMDir)
{
    if(bDSM == false)
        return "";

    if(aDSMDir.length() == 0)
        return "";
    aDSMDir += "/";
    cXML_ParamNuage3DMaille aNuageIn = StdGetObjFromFile<cXML_ParamNuage3DMaille>
    (
    aDSMDir + aDSMFile,
    StdGetFileXMLSpec("SuperposImage.xml"),
    "XML_ParamNuage3DMaille",
    "XML_ParamNuage3DMaille"
    );

    cImage_Profondeur aImDSM = aNuageIn.Image_Profondeur().Val();

    return aImDSM.Image();
}

Pt2dr cDSMInfo::GetOriPlani()
{
    if(bDSM == false)
        return Pt2dr(0,0);

    return mOriPlani;
}

Pt2dr cDSMInfo::GetResolPlani()
{
    if(bDSM == false)
        return Pt2dr(0,0);

    return mResolPlani;
}

Pt2di cDSMInfo::GetDSMSz()
{
    if(bDSM == false)
        return Pt2di(0,0);

    return mDSMSz;
}

bool cDSMInfo::GetIfDSMIsValid()
{
    return bDSM;
}

/*******************************************/
/****** cGet3Dcoor  ******/
/*******************************************/

cGet3Dcoor::cGet3Dcoor(std::string aNameOri)
{
    int aType = eTIGB_Unknown;
    mCam1 = cBasicGeomCap3D::StdGetFromFile(aNameOri,aType);

    bDSM = false;
}

double cGet3Dcoor::GetGSD()
{
    double dZL = mCam1->GetAltiSol();

    Pt2dr aCent(double(mCam1->SzBasicCapt3D().x)/2,double(mCam1->SzBasicCapt3D().y)/2);
    Pt2dr aCentNeigbor(aCent.x+1, aCent.y);

    Pt3dr aCentTer = mCam1->ImEtZ2Terrain(aCent, dZL);
    Pt3dr aCentNeigborTer = mCam1->ImEtZ2Terrain(aCentNeigbor, dZL);

    double dist = pow(pow(aCentTer.x-aCentNeigborTer.x,2) + pow(aCentTer.y-aCentNeigborTer.y,2), 0.5);

    return dist;
}

cDSMInfo cGet3Dcoor::SetDSMInfo(std::string aDSMFile, std::string aDSMDir)
{
    Pt2di aDSMSz = cDSMInfo::GetDSMSz(aDSMFile, aDSMDir);
    cDSMInfo aDSMInfo(aDSMSz, aDSMFile, aDSMDir);
    bDSM = aDSMInfo.GetIfDSMIsValid();
    return aDSMInfo;
}

/*
TIm2D<float,double> cGet3Dcoor::SetDSMInfo(std::string aDSMFile, std::string aDSMDir)
{
    //if(aDSMFile.length() > 0)
    {
        aDSMDir += "/";
        bDSM = true;

        cXML_ParamNuage3DMaille aNuageIn = StdGetObjFromFile<cXML_ParamNuage3DMaille>
        (
        aDSMDir + aDSMFile,
        StdGetFileXMLSpec("SuperposImage.xml"),
        "XML_ParamNuage3DMaille",
        "XML_ParamNuage3DMaille"
        );

        mDSMSz = aNuageIn.NbPixel();

        cImage_Profondeur aImDSM = aNuageIn.Image_Profondeur().Val();
        std::string aImName = aDSMDir + aImDSM.Image();
        Tiff_Im aImDSMTif(aImName.c_str());

        Pt2di aSzOut = mDSMSz;
        TIm2D<float,double> aTImDSM(aSzOut);
        ELISE_COPY
        (
        aTImDSM.all_pts(),
        aImDSMTif.in(),
        aTImDSM.out()
        );

        mFOM = StdGetFromPCP(aDSMDir+StdPrefix(aImDSM.Image())+".xml",FileOriMnt);

        mOriPlani = mFOM.OriginePlani();
        mResolPlani = mFOM.ResolutionPlani();

        return aTImDSM;
    }
}
*/
//get rough 3D coor with mean altitude
Pt3dr cGet3Dcoor::GetRough3Dcoor(Pt2dr aPt1)
{
    double dZ = mCam1->GetAltiSol();
    return mCam1->ImEtZ2Terrain(aPt1, dZ);
}

Pt2dr cGet3Dcoor::Get2Dcoor(Pt3dr aTer)
{
    Pt2dr aPLPred;
    //aPLPred = mCam1->R3toF2(aTer);
    aPLPred = mCam1->Ter2Capteur(aTer);

    return aPLPred;
}

//get 3d coordinate from DSM, if no DSM, get rough 3D coor with mean altitude
Pt3dr cGet3Dcoor::Get3Dcoor(Pt2dr aPt1, cDSMInfo aDSMInfo, bool& bPrecise, bool bPrint, double dThres)
{
    bPrecise = true;

    Pt3dr aTer(0,0,0);
    Pt2dr ptPrj;

    double dZ = mCam1->GetAltiSol();
    double dDis = 0;
    int nIter = 0;

    if(bPrint)
        printf("--->>>AltiSol: %.2lf\n", dZ);

    if(bDSM == true)
    {
        Pt2dr aOriPlani = aDSMInfo.GetOriPlani();
        Pt2dr aResolPlani = aDSMInfo.GetResolPlani();
        Pt2di aDSMSz = aDSMInfo.GetDSMSz();
        do
        {
            aTer = mCam1->ImEtZ2Terrain(aPt1, dZ);

            Pt2di aPt2;
            aPt2.x = int((aTer.x - aOriPlani.x)/aResolPlani.x + 0.5);
            aPt2.y = int((aTer.y - aOriPlani.y)/aResolPlani.y + 0.5);

            //out of border of the DSM
            if(aPt2.x<0 || aPt2.y<0 || aPt2.x >= aDSMSz.x || aPt2.y >= aDSMSz.y)
            {
                bPrecise = false;
                if(bPrint == true)
                    printf("Point (%.2lf, %.2lf) out of border of the DSM (Projected px in DSM: %d, %d; DSM size: %d, %d), hence use average altitude %.2lf instead.\n", aPt1.x, aPt1.y, aPt2.x, aPt2.y, aDSMSz.x, aDSMSz.y, mCam1->GetAltiSol());
            }
            else if(aDSMInfo.GetMasqValue(aPt2) < 0.0001){
                bPrecise = false;
                if(bPrint == true)
                    printf("Point (%.2lf, %.2lf) out of mask of the DSM (Projected px in DSM: %d, %d), hence use average altitude %.2lf instead.\n", aPt1.x, aPt1.y, aPt2.x, aPt2.y, mCam1->GetAltiSol());
            }

            //don't converge
            if(nIter > 100){
                bPrecise = false;
                if(bPrint == true){
                    printf("Iteration > 100, hence use average altitude instead. ");
                    printf("aTer: %.2lf, %.2lf, %.2lf\n", aTer.x, aTer.y, aTer.z);
                }
            }

            if(bPrecise == false)
            {
                aTer = GetRough3Dcoor(aPt1);
                return aTer;
            }

            dZ =  aDSMInfo.GetDSMValue(aPt2);
            aTer.z = dZ;

            ptPrj = mCam1->Ter2Capteur(aTer);
            dDis = pow(pow(aPt1.x-ptPrj.x, 2) + pow(aPt1.y-ptPrj.y, 2), 0.5);

            if(bPrint == true)
            {
                printf("nIter: %d; PxInDSM: [%d, %d], dZ: %.2lf, aTer.x: %.2lf, aTer.y: %.2lf, aTer.z: %.2lf, dDis: %.2lf, dThres: %.2lf\n", nIter, aPt2.x, aPt2.y, dZ, aTer.x, aTer.y, aTer.z, dDis, dThres);
                printf("ptOri: %.2lf %.2lf; ptReproj: %.2lf %.2lf\n", aPt1.x,aPt1.y,ptPrj.x,ptPrj.y);
            }
            nIter++;
        }
        while(dDis > dThres);
    }
    else
        aTer = GetRough3Dcoor(aPt1);

    return aTer;
}

void GetRandomNum(int nMin, int nMax, int nNum, std::vector<int> & res)
{
    //srand((int)time(0));
    int idx = 0;
    for(int i=0; i<nNum; i++)
    {
        bool bRepeat = false;
        int nIter = 0;
        do
        {
            bRepeat = false;
            nIter++;
            idx = rand() % (nMax - nMin) + nMin;
            //printf("For %dth seed, %dth generation, random value: %d\n", i, nIter, idx);
            for(int j=0; j<int(res.size()); j++)
            {
                if(idx == res[j]){
                    bRepeat = true;
                    break;
                }
            }
        }
        while(bRepeat == true);
        res.push_back(idx);
    }
}

void GetRandomNum(double dMin, double dMax, int nNum, std::vector<double> & res)
{
    //srand((int)time(0));
    int idx = 0;
    for(int i=0; i<nNum; i++)
    {
        bool bRepeat = false;
        int nIter = 0;
        do
        {
            bRepeat = false;
            nIter++;
            idx = (rand()*1.0/RAND_MAX)*(dMax-dMin) + dMin;
            //printf("For %dth seed, %dth generation, random value: %d\n", i, nIter, idx);
            /*
            for(int j=0; j<int(res.size()); j++)
            {
                if(fabs(idx - res[j]) < 0.00001){
                    bRepeat = true;
                    break;
                }
            }
            */
        }
        while(bRepeat == true);
        res.push_back(idx);
    }
}

bool GetImgListVec(std::string aFullPattern, std::vector<std::string>& aVIm, bool bPrint)
{
    bool bTxt = false;
    //image list
    if(aFullPattern.substr(aFullPattern.length()-4,4) == ".txt")
    {
        if (ELISE_fp::exist_file(aFullPattern) == false)
            printf("File %s does not exist.\n", aFullPattern.c_str());

        std::string s;

        ifstream in1(aFullPattern);
        if(bPrint)
            printf("Images in %s:\n", aFullPattern.c_str());
        while(getline(in1,s))
        {
            aVIm.push_back(s);
            if(bPrint)
                printf(" - %s\n", s.c_str());
        }
        bTxt = true;
    }
    //image pattern
    else
    {
        // Initialize name manipulator & files
        std::string aDirImages,aPatIm;
        SplitDirAndFile(aDirImages,aPatIm,aFullPattern);

        cInterfChantierNameManipulateur * aICNM=cInterfChantierNameManipulateur::BasicAlloc(aDirImages);
        const std::vector<std::string> aSetIm = *(aICNM->Get(aPatIm));

        if(bPrint)
            std::cout<<"Selected files:"<<std::endl;
        for (unsigned int i=0;i<aSetIm.size();i++)
        {
            if(bPrint)
                std::cout<<" - "<<aSetIm[i]<<std::endl;
            aVIm.push_back(aSetIm[i]);
        }
    }
    return bTxt;
}

bool FallInBox(Pt2dr* aPCorner, Pt2dr aLeftTop, Pt2di aRightLower)
{
    if((aPCorner[0].x < aLeftTop.x) && (aPCorner[1].x < aLeftTop.x) && (aPCorner[2].x < aLeftTop.x) && (aPCorner[3].x < aLeftTop.x))
        return false;

    if((aPCorner[0].y < aLeftTop.y) && (aPCorner[1].y < aLeftTop.y) && (aPCorner[2].y < aLeftTop.y) && (aPCorner[3].y < aLeftTop.y))
        return false;

    if((aPCorner[0].x > aRightLower.x) && (aPCorner[1].x > aRightLower.x) && (aPCorner[2].x > aRightLower.x) && (aPCorner[3].x > aRightLower.x))
        return false;

    if((aPCorner[0].y > aRightLower.y) && (aPCorner[1].y > aRightLower.y) && (aPCorner[2].y > aRightLower.y) && (aPCorner[3].y > aRightLower.y))
        return false;

    return true;
}

void ReadXml(std::string & aImg1, std::string & aImg2, std::string aSubPatchXml, std::vector<std::string>& vPatchesL, std::vector<std::string>& vPatchesR, std::vector<cElHomographie>& vHomoL, std::vector<cElHomographie>& vHomoR)
{
    cout<<aSubPatchXml<<endl;
    cSetOfPatches aSOMAF = StdGetFromSI(aSubPatchXml, SetOfPatches);

    std::list<cMes1Im>::const_iterator itIms = aSOMAF.Mes1Im().begin();

    cMes1Im aIms1 = * itIms;
    itIms++;
    cMes1Im aIms2 = * itIms;

    aImg1 = aIms1.NameIm();
    aImg2 = aIms2.NameIm();

    for(std::list<cOnePatch1I>::const_iterator itF = aIms1.OnePatch1I().begin() ; itF != aIms1.OnePatch1I().end() ; itF++)
    {
        cOnePatch1I aMAF = *itF;
        vPatchesL.push_back(aMAF.NamePatch());
        vHomoL.push_back(aMAF.PatchH());
    }

    for(std::list<cOnePatch1I>::const_iterator itF = aIms2.OnePatch1I().begin() ; itF != aIms2.OnePatch1I().end() ; itF++)
    {
        cOnePatch1I aMAF = *itF;
        vPatchesR.push_back(aMAF.NamePatch());
        vHomoR.push_back(aMAF.PatchH());
    }
}

void GetBoundingBox(Pt3dr* ptTerrCorner, int nLen, Pt3dr& minPt, Pt3dr& maxPt)
{
    minPt = ptTerrCorner[0];
    maxPt = ptTerrCorner[0];
    for(int i=0; i<nLen; i++){
        Pt3dr ptCur = ptTerrCorner[i];

        if(minPt.x > ptCur.x)
            minPt.x = ptCur.x;
        if(maxPt.x < ptCur.x)
            maxPt.x = ptCur.x;

        if(minPt.y > ptCur.y)
            minPt.y = ptCur.y;
        if(maxPt.y < ptCur.y)
            maxPt.y = ptCur.y;

        if(minPt.z > ptCur.z)
            minPt.z = ptCur.z;
        if(maxPt.z < ptCur.z)
            maxPt.z = ptCur.z;
    }
}

bool CheckRange(int nMin, int nMax, double & value)
{
    if(nMax < nMin)
        return false;
    if(value < nMin)
        value = nMin;
    if(value > nMax)
        value = nMax;
    return true;
}

std::string GetScaledImgName(std::string aImgName, Pt2di ImgSz, double dScale)
{
    int nSz1 = int(max(ImgSz.x, ImgSz.y)*1.0/dScale);

    //cout<<max(ImgSz.x, ImgSz.y)*1.0/nSz1<<endl;
    double dScaleNm = max(ImgSz.x, ImgSz.y)*1.0/nSz1;
    int nScaleNm = int(dScaleNm  + 0.5);
    if(nScaleNm < 10)
        nScaleNm *= 10;

    std::string aImgScaledName = "Resol" + ToString(nScaleNm) + "_Teta0_" + aImgName;

    return aImgScaledName;
}

void ExtractSIFT(std::string aImgName, std::string aDir, double dScale)
{
    std::string aImgNameWithDir = aDir+"/"+aImgName;
    if (ELISE_fp::exist_file(aImgNameWithDir) == false)
    {
        cout<<aImgNameWithDir<<" didn't exist, hence skipped"<<endl;
        return;
    }

    Tiff_Im aRGBIm1(aImgNameWithDir.c_str());
    Pt2di ImgSz = aRGBIm1.sz();
    int nSz1 = int(max(ImgSz.x, ImgSz.y)*1.0/dScale);

    std::string aComm;
    aComm = MMBinFile(MM3DStr) + "PastDevlop " + aImgName + " Sz1=" + ToString(nSz1) +" Sz2=-1";
    cout<<aComm<<endl;
    System(aComm);

    std::string aImgScaledName = GetScaledImgName(aImgName, ImgSz, dScale);

    aComm = MMBinFile(MM3DStr) + "SIFT " + aDir+"/Pastis/"+aImgScaledName + " -o " + aDir+"/Pastis/LBPp"+aImgScaledName+".dat";
    cout<<aComm<<endl;
    System(aComm);
}

/*
void ExtractSIFT(std::string aFullName, std::string aDir)
{
    cInterfChantierNameManipulateur::BasicAlloc(DirOfFile(aFullName));
    cout<<aFullName<<endl;

    //Tiff_Im::StdConvGen(aFullName,1,true,true);
    Tiff_Im::StdConvGen(aFullName,1,false,true);

    std::string aGrayImgName = aFullName + "_Ch1.tif";

    //if RGB image
    if( ELISE_fp::exist_file(aDir + "/Tmp-MM-Dir/" + aGrayImgName) == true)
    {
        std::string aComm;
        aComm = "mv " + aDir + "/Tmp-MM-Dir/" + aGrayImgName + " " + aGrayImgName;
        cout<<aComm<<endl;
        System(aComm);

        aComm = MMBinFile(MM3DStr) + "SIFT " + aGrayImgName;
        cout<<aComm<<endl;
        System(aComm);

        aComm = "mv " + StdPrefix(aGrayImgName)+".key" + " "+StdPrefix(aFullName)+".key";
        cout<<aComm<<endl;
        System(aComm);

        aComm = "rm " + aGrayImgName;
        cout<<aComm<<endl;
        System(aComm);
    }
    //gray image
    else
    {
        std::string aCom = MMBinFile(MM3DStr) + "SIFT " + aFullName;
        cout<<aCom<<endl;
        System(aCom);
    }
}
*/
