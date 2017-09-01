#include "dsf_Mux.h"

uint8_t dsf_Mux::mux(uint8_t select, uint8_t tempo, uint8_t temperatura)
{
	switch(select)
	{
	case 0:
		return tempo;
	case 1:
		return temperatura;
	}
}
