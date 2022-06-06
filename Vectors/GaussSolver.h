#pragma once
#include "My_matrix.h"

class GaussSolver {
public:
	//GaussSolver();
	//~GaussSolver();
	std::vector<Vector> solve(const Matrix& A, const Vector& b) {
		Matrix copyA = A;
		Vector copyV = b;
		std::vector<int> posMax(copyA.get_m());
		for (int i = 0; i < copyA.get_m(); i++) {
			posMax[i] = -1;
		}
		int rank = copyA.get_m() < copyA.get_n() ? copyA.get_m() : copyA.get_n();
		Matrix copyA1 = copyA.down_triangle(copyA, copyV, posMax);
		Matrix copyA2 = copyA1.upper_triangle(copyA1, copyV);
		Vector proverka(copyA2.get_n());
		if (copyA.proverka(copyA2, copyV)) {
			std::cout << "Net resheniy" << std::endl;
			return std::vector<Vector>();
		}
		double tmp;
		int position;
		int real_rank = rank;
		if (copyA2.get_m() == copyA2.get_n()) {
			for (int i = 0; i < rank; i++) {
				tmp = copyA2.Max(copyA2, i, position);
				if (tmp == 0) {
					real_rank--;
				}
			}
			position = 0;
			if (real_rank == rank) {
				std::vector<Vector> res(1);
				res[0].resize(rank);
				for (int i = 0; i < rank; i++) {
					if (copyA2.Max(copyA2, i, position) == 1) {
						res[0][position] = copyV[i];
					}
				}
				std::cout << res[0] << std::endl;
				return res;
			}
			else if (real_rank != rank) {
				std::vector<int> Pass(copyA2.get_n());
				int size = rank - real_rank;
				std::vector<Vector> res(size + 1);
				for (int i = 0; i < size + 1; i++) {
					res[i].resize(copyA2.get_n());
				}
				for (int i = 0; i < rank; i++) {
					if (copyA2.Max(copyA2, i, position) == 1) {
						res[0][position] = copyV[i];
					}
				}
				for (int i = 1; i < size + 1; i++) {
					for (int j = 0; j < copyA2.get_n(); j++) {
						if (Pass[j] == 0) {
							bool p = true;

							for (int k = 0; k < copyA2.get_m(); k++) {
								if (j == posMax[k] && copyA2[k] != proverka) {
									p = false;
								}
							}

							if (p == false) {
								continue;
							}
							else {
								res[i][j] = 1;
								for (int k = 0; k < copyA2.get_m(); k++) {
									if (copyA2[k] != proverka && posMax[k] != -1) {
										res[i][posMax[k]] = -copyA2[k][j];
									}
								}
								Pass[j] = 1;
								break;
								//Pass[j] == 1;

							}
						}

					}
				}
				for (int i = 0; i < size + 1; i++) {
					std::cout << "Vector " << i<< std::endl<< res[i] << std::endl;
				}
				return res;
			}
		}
		else if (copyA2.get_m() > copyA2.get_n()) {
			int m = copyA2.get_m();
			for (int i = 0; i < copyA2.get_m(); i++) {
				tmp = copyA2.Max(copyA2, i, position);
				if (tmp == 0) {
					m--;
				}
			}
			if (m == rank) {
				std::vector<Vector> res(1);
				res[0].resize(rank);
				for (int i = 0; i < rank; i++) {
					if (copyA2.Max(copyA2, i, position) == 1) {
						res[0][position] = copyV[i];
					}
				}
				std::cout << res[0] << std::endl;
				return res;
			}
			else {
				std::vector<int> Pass(copyA2.get_n());
				int size = rank - m;
				std::vector<Vector> res(size+1);
				for (int i = 0; i < size+1; i++) {
					res[i].resize(copyA2.get_n());
				}
				for (int i = 0; i < rank; i++) {
					if (copyA2.Max(copyA2, i, position) == 1 ) {
						res[0][position] = copyV[i];
					}
				}
				for (int i = 1; i < size + 1; i++) {
					for (int j = 0; j < copyA2.get_n(); j++) {
						if (Pass[j] == 0) {
							bool p = true;

							for (int k = 0; k < copyA2.get_m(); k++) {
								if (j == posMax[k] /*&& copyA2[k] != proverka*/ ) {
									p = false;
								}
							}

							if (p == false) {
								continue;
							}
							else {
								res[i][j] = 1;
								for (int k = 0; k < copyA2.get_m(); k++) {
									if (copyA2[k] != proverka && posMax[k] != -1) {
										res[i][posMax[k]] = -copyA2[k][j];
									}
								}
								Pass[j] = 1;
								break;
								//Pass[j] == 1;

							}
						}

					}
				}
				for (int i = 0; i < size + 1; i++) {
					std::cout << "Vector " << i << std::endl << res[i] << std::endl;
				}
				std::cout << copyA2 << std::endl;
				return res;
			}
		}
		else {
			for (int i = 0; i < rank; i++) {
				tmp = copyA2.Max(copyA2, i, position);
				if (tmp == 0) {
					real_rank--;
				}
			}
			std::vector<int> Pass(copyA2.get_n());
			int size = real_rank;
			std::vector<Vector> res(size);
			for (int i = 0; i < size; i++) {
				res[i].resize(copyA2.get_n());
			}
			for (int i = 0; i < rank; i++) {
				if (copyA2.Max(copyA2, i, position) == 1) {
					res[0][position] = copyV[i];
				}
			}
			for (int i = 1; i < size; i++) {				
				for (int j = 0; j < copyA2.get_n(); j++) {
					if (Pass[j] == 0) {
						bool p = true;

						for (int k = 0; k < copyA2.get_m(); k++) {
							if (j == posMax[k] && copyA2[k] != proverka) {
								p = false;
							}
						}

						if (p == false) {
							continue;
						}
						else {
							res[i][j] = 1;
							for (int k = 0; k < copyA2.get_m(); k++) {
								if (copyA2[k] != proverka && posMax[k] != -1) {
									res[i][posMax[k]] = -copyA2[k][j];
								}
							}
							Pass[j] = 1;
							break;
							//Pass[j] == 1;

						}
					}

				}
			}
			for (int i = 0; i < size; i++) {
				std::cout << "Vector " << i << std::endl << res[i] << std::endl;
			}
			std::cout << copyA2 << std::endl;
			return res;
		}

	};
	friend class Matrix;
};