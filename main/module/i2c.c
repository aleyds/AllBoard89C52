

static void _I2cInit(void)
{
	SCL=1;
	wy_delay(1);
	SDA=1;
	wy_delay(1);
}

static void _I2cStart(void)
{
	SDA=1;
	wy_delay(1);
	SCL=1;
	wy_delay(1);
	SDA=0;
	wy_delay(1);
}

static void _I2cRespons(void)
{
	H_U8 i = 0;
	SCL=1;
	wy_delay(1);
	while((SDA == 1) && (i < 255))
	{
		i++;
	}
	SCL=0;
	wy_delay(1);
}

static void _I2cStop(void)
{
	SDA=0;
	wy_delay(1);
	SCL=1;
	wy_delay(1);
	SDA=1;
	wy_delay(1);
}

static void _I2cWriteByte(H_U8 byte)
{
	H_U8 i= 0;
	H_U8 tmp = type;
	
	for(i = 0; i < 8; i++)
	{
		tmp=tmp<<1;
		SCL=0;
		wy_delay(1);
		SDA=CY;
		wy_delay(1);
		SCL=1;
		wy_delay(1);
	}
	SCL=0;
	wy_delay(1);
	SDA=1;
	wy_delay(1);
}

static H_U8 I2cReadByte(void)
{
	H_U8 i = 0;
	H_U8 k = 0;
	SCL=0;
	wy_delay(1);
	SDA=1;
	for(i = 0; i < 8; i++)
	{
		SCL=1;
		wy_delay(1);
		k=((k<<1)|SDA);
		SCL=0;
		wy_delay(1);
	}
	wy_delay(1);
	return k;
}
