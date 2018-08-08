#pragma once

namespace op_in
{
	template<class TIn>
	struct OP_IN_LVAL
	{
		const TIn& m_in;

		OP_IN_LVAL(const TIn& val)
			:m_in(val)
		{};

		template<class TWhat>
		auto operator*(const TWhat& what) const -> decltype(operator_in(m_in, what))
		{
			return operator_in(m_in, what);
		}

		template<class TWhat>
		auto operator*(TWhat& what) const -> decltype(operator_in(m_in, what))
		{
			return operator_in(m_in, what);
		}
	};

	class OP_IN_HELP{};
	template<class TIn>
	OP_IN_LVAL<TIn> operator*(const TIn& data, const OP_IN_HELP&)
	{
		return OP_IN_LVAL<TIn>(data);
	}
}
#define in *op_in::OP_IN_HELP{}*