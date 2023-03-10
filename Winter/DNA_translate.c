////////////////////////////////////////////////////////////
// CSC A48 - DNA alignment Pt. 1
//
// The goal of this assignment is to write a function that
// translates tripled (sets of 3) DNA nucleotide bases to
// the corresponding aminoacid.
//
// As a brief review of your Biology lessons, DNA is a double
// stranded chain of nucleic-acids, there are 4 types of
// nucleotides denoted by the letters:
//
// A, C, T, G
//
// The sequence of these nucleotides specifies the sequence
// in which aminoacids (the building blocks of proteins)
// are assembled into every single one of the proteins that
// make up the cells of most licing things (there are a 
// few that do not use DNA, opting instead to use the single
// stranded version called RNA, viruses tend to be sneaky
// that way!)
//
// Each set of 3 nucleotides specifies one aminoacid in
// a protein's specification.
//
// The goal of this exercise is for you to write a small
// function that takes in a DNA sequence (a string made up
// of letters ATCG in some sequence) and determines the
// corresponding sequence of aminoacids. Below, you will
// find a table listing each aminoacid, and the sequences
// of DNA nucleotides that specify that aminoacid.
// 
// Note that many aminoacids can be specified by more than
// one triplet!
//
//  Aminoacid   Single letter name	Triplets
//  Isoleucine 		I 		ATT, ATC, ATA
//  Leucine 		L 		CTT, CTC, CTA, CTG, TTA, TTG
//  Valine 		V 		GTT, GTC, GTA, GTG
//  Phenylalanine 	F 		TTT, TTC
//  Methionine 		M 		ATG
//  Cysteine 		C 		TGT, TGC
//  Alanine 		A 		GCT, GCC, GCA, GCG
//  Glycine 		G 		GGT, GGC, GGA, GGG
//  Proline 		P 		CCT, CCC, CCA, CCG
//  Threonine 		T		ACT, ACC, ACA, ACG
//  Serine 		S 		TCT, TCC, TCA, TCG, AGT, AGC
//  Tyrosine 		Y 		TAT, TAC
//  Tryptophan 		W 		TGG
//  Glutamine 		Q 		CAA, CAG
//  Asparagine 		N 		AAT, AAC
//  Histidine 		H 		CAT, CAC
//  Glutamic acid 	E 		GAA, GAG
//  Aspartic acid 	D 		GAT, GAC
//  Lysine 		K 		AAA, AAG
//  Arginine 		R 		CGT, CGC, CGA, CGG, AGA, AGG
//
//  Your task is to determine whether two DNA sequences use the
//  same number of each type of aminoacid (the order of the
//  amino-acids doesn't matter here).
//  To that end, you need to write a function that
//  takes a DNA sequence and converts it to the corresponding
//  sequence of aminoacids, for instance if the input sequence is:
//
//  AAGGAGTGTTTT
//
//  Your function must return
//
//  KECF
//
//  Then you need to write a function that takes in two DNA
//  sequences and determines whether they produce the same
//  numbers of each aminoacid. For example, if the sequence
//  of aminoacids for each of the input DNA sequences is
//
//  AATVKFAA    and    TAAVKAAF
//
//  The function must return 1 (they produce the same number
//  of each aminoacid). However, if the aminoacid sequences
//  are
//
//  TVFAAKVV    and    ECVAATFK
//
//  the function will return 0 (not the same number of each
//  aminoacid).
//
// (c) F. Estrada, March, 2022
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024  





void DNA_sequencing(char inputDNA[1024], char outputAminoAcids[1024])
{
    // This function receives two strings, one that contains a sequence
    // of DNA nucleotides (which MUST be composed of the letters
    // ACGT, no spaces or other symbols can appear here!), and
    // updates an initially empty string 'outputAminoAcids' with the
    // sequence of aminoacids corresponding to the input DNA sequence
    //
    // Try to make this function as compact (fewer lines of code, more
    // elegant, easier to read code) as possible. APply what you've
    // learned in Exercises 6-8, all of which helped you practice
    // using strings!

    // To Do:
    // Complete this function
	int c = 0;
	while(outputAminoAcids[c]!='\0'){
		outputAminoAcids[c] = '\0';
		c++;
	}
	int i = 0;
	char temp[MAX];
    while(inputDNA[i] !=0){
      i++;
    }
	i = i- (i%3);


	int o = 0;
	while(o != i){

		temp[0] = inputDNA[o];
		temp[1] = inputDNA[o+1];
		temp[2] = inputDNA[o+2];

		if ( strcmp(temp,"CTT") == 0 || strcmp(temp,"CTC") ==0 || strcmp(temp,"CTA") ==0 || strcmp(temp,"CTG") ==0 || strcmp(temp,"TTA") ==0 || strcmp(temp,"TTG")==0){
			strcat(outputAminoAcids,"L");
		}else if( strcmp(temp,"TCT") ==0 || strcmp(temp,"TCC") ==0 || strcmp(temp,"TCA") ==0 || strcmp(temp,"TCG") ==0 || strcmp(temp,"AGT") ==0 || strcmp(temp,"AGC")==0){
			strcat(outputAminoAcids,"S");
		}else  if(strcmp(temp,"CGT") ==0 || strcmp(temp,"CGC") ==0 || strcmp(temp,"CGA") ==0 || strcmp(temp,"CGG") ==0 || strcmp(temp,"AGA") ==0 ||strcmp(temp,"AGG")==0){
			strcat(outputAminoAcids,"R");
		} 
		  if(strcmp(temp,"GCT") ==0 || strcmp(temp,"GCC") ==0 || strcmp(temp,"GCA") ==0 || strcmp(temp,"GCG")==0){
			strcat(outputAminoAcids,"A");
		}else  if(strcmp(temp,"GGT") ==0 || strcmp(temp,"GGC") ==0 || strcmp(temp,"GGA") ==0 || strcmp(temp,"GGG")==0){
			strcat(outputAminoAcids, "G");
		}else  if(strcmp(temp,"ACT") ==0 || strcmp(temp,"ACC") ==0 || strcmp(temp,"ACA") ==0 || strcmp(temp,"ACG")==0){
			strcat(outputAminoAcids, "T");
		}else if(strcmp(temp,"CCT") ==0 || strcmp(temp,"CCC") ==0 || strcmp(temp,"CCA") ==0 || strcmp(temp,"CCG")==0){
			strcat(outputAminoAcids, "P");
		}else if(strcmp(temp,"GTT") ==0 || strcmp(temp,"GTC") ==0 || strcmp(temp,"GTA") ==0 || strcmp(temp,"GTG")==0){
			strcat(outputAminoAcids, "V");
		
		}else  if(strcmp(temp,"ATT") ==0 || strcmp(temp,"ATC") ==0 || strcmp(temp,"ATA")==0){
			strcat(outputAminoAcids, "I");
		}
		  if(strcmp(temp,"TTT") ==0 || strcmp(temp,"TTC")==0){
			strcat(outputAminoAcids, "F");
		}else if(strcmp(temp,"TGT") ==0 || strcmp(temp,"TGC")==0){
			strcat(outputAminoAcids, "C");
		}else if(strcmp(temp,"TAT") ==0 || strcmp(temp,"TAC")==0){
			strcat(outputAminoAcids, "Y");
		}else if(strcmp(temp,"CAA") ==0 || strcmp(temp,"CAG")==0){
			strcat(outputAminoAcids, "Q");
		}else if(strcmp(temp,"AAT") ==0 || strcmp(temp,"AAC")==0){
			strcat(outputAminoAcids, "N");
		}else if(strcmp(temp,"CAT") ==0 || strcmp(temp,"CAC")==0){
			strcat(outputAminoAcids, "H");
		}else if(strcmp(temp,"GAA") ==0 || strcmp(temp,"GAG")==0){
			strcat(outputAminoAcids, "E");
		}else if(strcmp(temp,"GAT") ==0 || strcmp(temp,"GAC")==0){
			strcat(outputAminoAcids, "D");
		}else if(strcmp(temp,"AAA") ==0 || strcmp(temp,"AAG")==0){
			strcat(outputAminoAcids, "K");
		}
		  if(strcmp(temp,"ATG")==0){
			strcat(outputAminoAcids, "M");
		}else if(strcmp(temp,"TGG")==0){
			strcat(outputAminoAcids, "W");
		}
		o = o+3;
	}

}

void sortString(char string[MAX]){
	int i,j,k;
	char temp;
	k=strlen(string);
  for(i=1;i<k;i++)
    for(j=0;j<k-i;j++)
	if(string[j]>string[j+1])
	{
	  temp=string[j];
	  string[j] = string[j+1];
	  string[j+1]=temp;
	}
}
int amino_matching(char inputDNA1[1024], char inputDNA2[1024])
{
    // This function receives two strings representing DNA
    // sequences. It returns 1 if the sequences produce the
    // same number of each type of aminoacid. Think carefully
    // about the best (simplest?) way to to this.

    // To Do:
    // Complete this function
	char temp1[MAX] , temp2[MAX];
	DNA_sequencing(inputDNA1, temp1);
	DNA_sequencing(inputDNA2, temp2);

	sortString(temp1);
	sortString(temp2);

	if(strcmp(temp1,temp2) ==0) return 1;
    return 0;
}

#ifndef __testing

int main()
{
	char DNAseq1[1024]="CTTATTGTTCCAATGTGGCGGCACTACACGTGCGTTATC";
	char DNAseq2[1024]="ATTTATTGTACATATCATCGTTGGATGCCCGTAATATTG";
        char DNAseq3[1024]="ATCGTTTGCACGTACCACCGGTGGATGCCAGTTATTCTT";
	char aminoAcids[1024]="";

	printf("Input DNA sequence 1: %s\n",DNAseq1);
	DNA_sequencing(DNAseq1,aminoAcids);
	printf("Output aminoacid sequence 1: %s\n",aminoAcids);

	printf("Input DNA sequence 2: %s\n",DNAseq2);
	DNA_sequencing(DNAseq2,aminoAcids);
	printf("Output aminoacid sequence 2: %s\n",aminoAcids);

	printf("Input DNA sequence 3: %s\n",DNAseq3);
	DNA_sequencing(DNAseq3,aminoAcids);
	printf("Output aminoacid sequence 3: %s\n",aminoAcids);

	if (amino_matching(DNAseq1,DNAseq2)==1)
	{
		printf("Sequence 1 matches sequence 2 in aminoacids\n");
	}
	 else
	{
		printf("Sequence 1 does not match sequence 2 in aminoacids\n");
	}

	if (amino_matching(DNAseq1,DNAseq3)==1)
	{
		printf("Sequence 1 matches sequence 3 in aminoacids\n");
	}
	 else
	{
		printf("Sequence 1 does not match sequence 3 in aminoacids\n");
	}

	if (amino_matching(DNAseq2,DNAseq3)==1)
	{
		printf("Sequence 2 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 2 does not match sequence 3 in aminoacids\n");
	}

	return 0;
}

#endif
