#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) temp=a;a=b;b=temp;		//értékek felcserélése


//rendező alg kifejtve, csak a szükséges lépések elvégzésével
void odd_even_sort(float *data)
{
	float temp = 0.0f;

	for (int i = 1; i < 24; i += 2) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
	}

	for (int i = 1; i < 22; i += 4) {
		if (data[i] > data[i + 2])
		{
			SWAP(data[i], data[i + 2]);
		}
		if (data[i + 1] > data[i + 3])
		{
			SWAP(data[i + 1], data[i + 3]);
		}
	}

	for (int i = 2; i < 23; i += 4) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
	}

	for (int i = 1; i < 22; i += 8) {
		if (data[i] > data[i + 4])
		{
			SWAP(data[i], data[i + 4]);
		}
		if (data[i + 1] > data[i + 5])
		{
			SWAP(data[i + 1], data[i + 5]);
		}
		if (data[i + 2] > data[i + 6])
		{
			SWAP(data[i + 2], data[i + 6]);
		}
		if (data[i + 3] > data[i + 7])
		{
			SWAP(data[i + 3], data[i + 7]);
		}


	}

	for (int i = 3; i < 22; i += 8) {
		if (data[i] > data[i + 2])
		{
			SWAP(data[i], data[i + 2]);
		}
		if (data[i + 1] > data[i + 3])
		{
			SWAP(data[i + 1], data[i + 3]);
		}
	}

	for (int i = 2; i < 22; i += 8) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
		if (data[i + 2] > data[i + 3])
		{
			SWAP(data[i + 2], data[i + 3]);
		}
		if (data[i + 4] > data[i + 5])
		{
			SWAP(data[i + 4], data[i + 5]);
		}
	}

	if (data[0] > data[8])
	{
		SWAP(data[0], data[8]);
	}

	for (int i = 9; i < 17; i++) {
		if (data[i] > data[i + 8])
		{
			SWAP(data[i], data[i + 8]);
		}
	}

	if (data[0] > data[4])
	{
		SWAP(data[0], data[4]);
	}

	for (int i = 13; i < 17; i++) {
		if (data[i] > data[i + 4])
		{
			SWAP(data[i], data[i + 4]);
		}
	}

	if (data[0] > data[2])
	{
		SWAP(data[0], data[2]);
	}

	if (data[3] > data[5])
	{
		SWAP(data[3], data[5]);
	}

	if (data[4] > data[6])
	{
		SWAP(data[4], data[6]);
	}

	for (int i = 11; i < 20; i += 4) {
		if (data[i] > data[i + 2])
		{
			SWAP(data[i], data[i + 2]);
		}
		if (data[i + 1] > data[i + 3])
		{
			SWAP(data[i + 1], data[i + 3]);
		}
	}

	for (int i = 0; i < 7; i += 2) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
	}

	for (int i = 9; i < 23; i += 2) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
	}

	for (int i = 0; i < 8; i++) {
		if (data[i] > data[i + 16])
		{
			SWAP(data[i], data[i + 16]);
		}
	}

	for (int i = 1; i < 9; i++) {
		if (data[i] > data[i + 8])
		{
			SWAP(data[i], data[i + 8]);
		}
	}

	for (int i = 5; i < 16; i += 8) {
		if (data[i] > data[i + 4])
		{
			SWAP(data[i], data[i + 4]);
		}
		if (data[i + 1] > data[i + 5])
		{
			SWAP(data[i + 1], data[i + 5]);
		}
		if (data[i + 2] > data[i + 6])
		{
			SWAP(data[i + 2], data[i + 6]);
		}
		if (data[i + 3] > data[i + 7])
		{
			SWAP(data[i + 3], data[i + 7]);
		}
	}

	if (data[11] > data[13])
	{
		SWAP(data[11], data[13]);
	}
	if (data[12] > data[14])
	{
		SWAP(data[12], data[14]);
	}
	if (data[12] > data[13])
	{
		SWAP(data[12], data[13]);
	}

	if (data[10] > data[12])
	{
		SWAP(data[10], data[12]);
	}
	if (data[8] > data[12])
	{
		SWAP(data[8], data[12]);
	}
}
