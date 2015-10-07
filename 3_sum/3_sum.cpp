#include <vector>
#include <algorithm>

namespace snail
{

	namespace detail
	{

		template<class T>
		static inline void jumpr(const std::vector<T>& vec, std::size_t& pos, const std::size_t max)
		{
			for (++pos; pos < max && vec[pos] == vec[pos - 1]; ++pos);
		}

		template<class T>
		static inline void jumpl(const std::vector<T>& vec, std::size_t& pos, const std::size_t min)
		{
			for (--pos; pos > min && vec[pos] == vec[pos + 1]; --pos);
		}

		template<class T>
		static void twosum(const std::vector<T>& vec, const T& sum, std::size_t head, const std::vector<T>& pre, std::vector<std::vector<T>>& res)
		{
			std::size_t tail = vec.size() - 1;

			T mid = sum / 2;
			if (mid < vec[head] || mid > vec[tail])
			{
				return;
			}

			while (head < tail)
			{
				T num = vec[head] + vec[tail];
				if (num == sum)
				{
					std::vector<T> newres = pre;
					newres.push_back(vec[head]);
					newres.push_back(vec[tail]);
					res.push_back(newres);
					jumpr(vec, head, tail);
					jumpl(vec, tail, head);
				}
				else if (num > sum)
				{
					jumpl(vec, tail, head);
				}
				else
				{
					jumpr(vec, head, tail);
				}
			}
		}

		template<class T>
		static void ksum(const std::vector<T>& vec, int k, const T& sum, std::size_t head, const std::vector<T>& pre, std::vector<std::vector<T>>& res)
		{
			if (k == 2)
			{
				twosum(vec, sum, head, pre, res);
			}
			else
			{
				std::size_t begin = head;
				std::size_t max = vec.size() - k + 1;
				while (begin < max && vec[begin] <= sum / (long signed int)k)
				{
					std::vector<T> newpre = pre;
					newpre.push_back(vec[begin]);
					ksum(vec, k - 1, sum - vec[begin], begin + 1, newpre, res);
					jumpr(vec, begin, max);
				}
			}
		}

	}

	template<class T>
	static std::vector<std::vector<T>> ksum(std::vector<T>& vec, int k, const T& sum)
	{
		std::vector<std::vector<T>> res;

		if (k <= 0 || (size_t)k > vec.size())
		{
			return res;
		}
		if (k == 1)
		{
			for (T& var : vec)
			{
				if (var == sum)
				{
					std::vector<T> newres;
					newres.push_back(var);
					res.push_back(newres);
					return res;
				}
			}
		}

		sort(vec.begin(), vec.end());

		std::vector<T> head;
		detail::ksum(vec, k, sum, 0, head, res);
		return res;
	}

}

class Solution {

public:

	vector<vector<int>> threeSum(vector<int>& nums) {
		return snail::ksum(nums, 3, 0);
	}

};