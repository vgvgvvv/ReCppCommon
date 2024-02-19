#pragma once

#define RE_ASSERT(CONDITION) \
do { \
	const auto __succ = (CONDITION); \
	assert(__succ); \
} while(0); \

#define RE_ASSERT_MSG(CONDITION, MSG) \
if (!(CONDITION))                         \
{                                         \
	RE_ERROR(MSG);                        \
	RE_ASSERT(false);                     \
}

#define RE_ASSERT_MSG_F(CONDITION, Format, ...) \
if (!(CONDITION))                         \
{                                         \
	RE_ERROR_F(Format, __VA_ARGS__);      \
	RE_ASSERT(false);                     \
}

#define NOT_SUPPORT_ASSERT(MSG) \
RE_ASSERT_MSG(false, MSG)