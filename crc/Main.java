package crc;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		int data_bits, divisor_bits, total_length;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of data bits");
		data_bits = sc.nextInt();
		int data[] = new int[data_bits];
		System.out.println("Enter the data bits");
		for(int i = 0; i < data_bits; i++)
			data[i] = sc.nextInt();
		System.out.println("Enter the number of divisor bits");
		divisor_bits = sc.nextInt();
		int divisor[] = new int[divisor_bits];
		System.out.println("Enter the divisor bits");
		for(int i = 0; i < divisor_bits; i++)
			divisor[i] = sc.nextInt();
		total_length = data_bits + divisor_bits - 1;
		int dividend[] = new int[total_length];
		int rem[] = new int[total_length];
		int crc[] = new int[total_length];
		for(int i=0; i<data.length; i++)
			dividend[i] = data[i];
		System.out.println("The dividend after appending zeros is");
		for(int i=0; i<dividend.length; i++)
			System.out.print(dividend[i]);
		for(int i=0; i<dividend.length; i++)
			rem[i] = dividend[i];
		rem = divide(dividend, divisor, rem);
		for(int i=0; i< rem.length; i++)
			crc[i] = dividend[i] ^ rem[i];
		System.out.println("The CRC code is ");
		for(int i=0; i<crc.length; i++)
			System.out.println(crc[i]);
		System.out.println("Enter the CRC code of length "+total_length);
		for(int i=0; i<total_length; i++)
			crc[i] = sc.nextInt();
		for(int i=0; i<crc.length; i++)
			rem[i] = crc[i];
		rem = divide(crc, divisor, rem);
		for(i=0; i<rem.length; i++)
		{
			if(rem[i]!=0)
			{
				System.out.println("Error");
				break;
			}
			if(i == rem.length-1)
			{
				System.out.println("No Error");
			}
		}
	}
	static int[] divide(int dividend[], int divisor[], int rem[])
	{
		int cur = 0;
		while(true)
		{
			for(int i=0; i<divisor.length; i++)
				rem[cur+i] = rem[cur+i] ^ divisor[i];
			while(rem[cur]==0 && cur != rem.length-1)
				cur++;
			if((rem.length-cur) < divisor.length)
				break;
		}
		return rem;
	}

}
