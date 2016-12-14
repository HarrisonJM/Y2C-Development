#pragma once

struct MA
{
	unsigned int id : 31;
	unsigned int isActive : 1;
	unsigned int dataItem : 30;
	unsigned int isDirtyData : 1;
	unsigned int isLocked : 1;
	unsigned int creationTimestamp;
	unsigned int lastUpdateTimestamp;
};
