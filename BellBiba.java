import java.io.*;
import java.util.*;
public class BellBiba
{
	public int number;
	public String[] user;
	public int[] prior,stored;
	public String[][] written;
	public BellBiba(int number)
	{
		this.number=number;
		user=new String[number];
		prior=new int[number];
		written=new String[number][10];
		stored=new int[number];
	}
	public void BellLaPadula()
	{
		System.out.println("Bell LaPadula\nFiles which a user can read");
		for(int i=0;i<number;i++)
		{
			System.out.println(user[i]);
			for(int j=prior[i]+1;j<number;j++)
			{
				int l=0;
				for(int ii=0;ii<number;ii++)
				{
					if(prior[ii]==j)
					{
						l=ii;
						break;
					}
				}
				for(int k=0;k<stored[l];k++)
				{
					System.out.println("-->"+written[l][k]);
				}
			}
			System.out.println();
		}
		System.out.println("Users and their accepted receipients");
		for(int i=0;i<number;i++)
		{
			System.out.println(user[i]);
			for(int j=prior[i]-1;j>=0;j--)
			{
				int l=0;
				for(int ii=0;ii<number;ii++)
				{
					if(prior[ii]==j)
					{
						l=ii;
						break;
					}
				}
				System.out.println("-->"+user[l]);
			}
			System.out.println();
		}
	}
	public void Biba()
	{
		System.out.println("Biba Model\nFiles which a user can read");
		for(int i=0;i<number;i++)
		{
			System.out.println(user[i]);
			for(int j=prior[i]-1;j>=0;j--)
			{
				int l=0;
				for(int ii=0;ii<number;ii++)
				{
					if(prior[ii]==j)
					{
						l=ii;
						break;
					}
				}
				for(int k=0;k<stored[l];k++)
				{
					System.out.println("-->"+written[l][k]);
				}
			}
			System.out.println();
		}
		System.out.println("Users and their accepted receipients");
		for(int i=0;i<number;i++)
		{
			System.out.println(user[i]);
			for(int j=prior[i]+1;j<number;j++)
			{
				int l=0;
				for(int ii=0;ii<number;ii++)
				{
					if(prior[ii]==j)
					{
						l=ii;
						break;
					}
				}
				System.out.println("-->"+user[l]);
			}
			System.out.println();
		}
	}
	public static void main(String[] argv)
	{
		BellBiba bb=new BellBiba(5);
		bb.user[0]="Abc";
		bb.user[1]="Def";
		bb.user[2]="Ghi";
		bb.user[3]="Jkl";
		bb.user[4]="Mno";
		bb.prior[0]=4;
		bb.prior[1]=2;
		bb.prior[2]=0;
		bb.prior[3]=1;
		bb.prior[4]=3;
		bb.stored[0]=2;
		bb.stored[1]=3;
		bb.stored[2]=1;
		bb.stored[3]=3;
		bb.stored[4]=2;
		bb.written[0][0]="Article1.pdf";
		bb.written[0][1]="Article2.pdf";
		bb.written[1][0]="Article3.docx";
		bb.written[1][1]="Article4.pdf";
		bb.written[1][2]="Article5.pdf";
		bb.written[2][0]="Article6.pdf";
		bb.written[3][0]="Article7.docx";
		bb.written[3][1]="Article8.rtf";
		bb.written[3][2]="Article9.pdf";
		bb.written[4][0]="Article10.pdf";
		bb.written[4][1]="Article11.pdf";
		bb.BellLaPadula();
		bb.Biba();
	}
}