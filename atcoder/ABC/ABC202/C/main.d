module ABC.ABC202.C.main;

import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

void main()
{
	//────────────────────────────────────────
	// Step 1. 入力
	//────────────────────────────────────────
	const int n = readln.chomp.to!int;
	string[] input = readln.split;
	int[] a;
	for (int i = 0; i < n; i++)
		a ~= input[i].to!int;
	input = readln.split;
	int[] b;
	for (int i = 0; i < n; i++)
		b ~= input[i].to!int;
	input = readln.split;
	int[] c;
	for (int i = 0; i < n; i++)
		c ~= input[i].to!int - 1;

	//────────────────────────────────────────
	// Step 2. 解く
	//────────────────────────────────────────
	int[100_001] cnt;
	for (int j = 0; j < n; j++) {
		cnt[b[c[j]]]++;
	}

	long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += cnt[a[i]];
	}

	//────────────────────────────────────────
	// Step 3. 出力
	//────────────────────────────────────────
	writeln(ans);
}