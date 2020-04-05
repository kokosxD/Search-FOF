#pragma once

namespace kokos{
	class Timer{
	private:
		unsigned int timer = 0;
	public:
		void Start() noexcept;

		const unsigned int Stop() const noexcept;
	};
}