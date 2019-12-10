#ifndef NAMESPACE_INT_H
#define NAMESPACE_INT_H

namespace Int
{
	enum Sign
	{
		positive = 0,
		negative
	};

	class Integer
	{
		int i;
		Sign s;
		
	public:
		Integer(int ii = 0)
			: i(ii)
			, s(i >= 0 ? positive : negative)
		{
		}

		Sign getSign() const { return s; }
		void setSign(Sign ss) { s = ss; }
	};
}

#endif // NAMESPACE_INT_H