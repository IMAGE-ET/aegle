/**
@file TagDictionaru.cpp

Created March 10th 2014
*/

#include "TagDictionary.h"

std::map<int, Tag_Description> TagDictionary::dictionary_;

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

TagDictionary::TagDictionary() 
{
	// check to see if dictionary has already been created
	if (dictionary_.size())
	{
		// create dictionary
		dictionary_[0x00080050] = ACCESSION_NUMBER;
		dictionary_[0x00080022] = ACQUISITION_DATE;
		dictionary_[0x00181310] = ACQUISITION_MATRIX;
		dictionary_[0x00200012] = ACQUISITION_NUMBER;
		dictionary_[0x00080032] = ACQUISITION_TIME;
		dictionary_[0x00180025] = ANGIO_FLAG;
		dictionary_[0x00280100] = BITS_ALLOCATED;
		dictionary_[0x00280101] = BITS_STORED;
		dictionary_[0x00280011] = COLUMNS;
		dictionary_[0x00181318] = DB_DT;
		dictionary_[0x00181000] = DEVICE_SERIAL_NUMBER;
		dictionary_[0x00180086] = ECHO_NUMBERS;
		dictionary_[0x00180081] = ECHO_TIME;
		dictionary_[0x00180091] = ECHO_TRAIN_LENGTH;
		dictionary_[0x00020001] = FILE_META_INFORMATION_VERSION;               
		dictionary_[0x00181314] = FLIP_ANGLE;
		dictionary_[0x00200052] = FRAME_OF_REFERENCE_UID;
		dictionary_[0x00020000] = GROUP_LENGTH;
		dictionary_[0x00280102] = HIGH_BIT;
		dictionary_[0x00204000] = IMAGE_COMMENTS;
		dictionary_[0x00080023] = IMAGE_DATE;
		dictionary_[0x00200013] = IMAGE_NUMBER;
		dictionary_[0x00200037] = IMAGE_ORIENTATION;
		dictionary_[0x00200032] = IMAGE_POSITION;
		dictionary_[0x00080033] = IMAGE_TIME;
		dictionary_[0x00080008] = IMAGE_TYPE;                                  
		dictionary_[0x00180085] = IMAGED_NUCLEUS;
		dictionary_[0x00180084] = IMAGING_FREQUENCY;
		dictionary_[0x00020012] = IMPLEMENTATION_CLASS_UID;
		dictionary_[0x00020013] = IMPLEMENTATION_VERSION_NAME;
		dictionary_[0x00080080] = INSTITUTION_NAME;
		dictionary_[0x00280107] = LARGEST_IMAGE_PIXEL_VALUE;
		dictionary_[0x00282110] = LOSSY_IMAGE_COMPRESSION;
		dictionary_[0x00282112] = LOSSY_IMAGE_COMPRESSION_RATIO;
		dictionary_[0x00180087] = MAGNETIC_FIELD_STRENGTH;
		dictionary_[0x00080070] = MANUFACTURER;
		dictionary_[0x00081090] = MANUFACTURERS_MODEL_NAME;
		dictionary_[0x00020002] = MEDIA_STORAGE_SOP_CLASS_UID;                     
		dictionary_[0x00020003] = MEDIA_STORAGE_SOP_INSTANCE_UID;                 
		dictionary_[0x00080060] = MODALITY;
		dictionary_[0x00180023] = MR_ACQUISITION_TYPE;
		dictionary_[0x00180083] = NUMBER_OF_AVERAGES;
		dictionary_[0x00180089] = NUMBER_OF_PHASE_ENCODING_STEPS;
		dictionary_[0x00081070] = OPERATORS_NAME;
		dictionary_[0x00100020] = PATIENT_ID;
		dictionary_[0x00185100] = PATIENT_POSITION;
		dictionary_[0x00101010] = PATIENTS_AGE;
		dictionary_[0x00100010] = PATIENTS_NAME;
		dictionary_[0x00101030] = PATIENTS_WEIGHT;
		dictionary_[0x00180094] = PERCENT_PHASE_FIELD_OF_VIEW;
		dictionary_[0x00180093] = PERCENT_SAMPLING;
		dictionary_[0x00400275] = PERFORMED_PROCEDURE_STEP_DESCRIPTION;
		dictionary_[0x00400244] = PERFORMED_PROCEDURE_STEP_START_DATE;
		dictionary_[0x00400245] = PERFORMED_PROCEDURE_STEP_START_TIME;
		dictionary_[0x00181312] = PHASE_ENCODING_DIRECTION;
		dictionary_[0x00280004] = PHOTOMETRIC_INTERPRETATION;
		dictionary_[0x00180095] = PIXEL_BANDWIDTH;
		dictionary_[0x00280103] = PIXEL_REPRESENTATION;
		dictionary_[0x00280030] = PIXEL_SPACING;
		dictionary_[0x00181030] = PROTOCOL_NAME;
		dictionary_[0x00081140] = REFERENCED_IMAGE_SEQUENCE;
		dictionary_[0x00081120] = REFERENCED_PATIENT_SEQUENCE;
		//REFERENCED_SOP_CLASS_UID,                     
		//REFERENCED_SOP_INSTANCE_UID,                    
		dictionary_[0x00081111] = REFERENCED_STUDY_COMPONENT_SEQUENCE;
		dictionary_[0x00081110] = REFERENCED_STUDY_SEQUENCE;
		dictionary_[0x00080090] = REFERRING_PHYSICIANS_NAME;
		dictionary_[0x00180080] = REPETITION_TIME;
		dictionary_[0x00400275] = REQUEST_ATTRIBUTES_SEQUENCE;
		dictionary_[0x00321060] = REQUESTED_PROCEDURE_DESCRIPTION;
		//REQUESTED_PROCEDURE_ID,                
		dictionary_[0x00321032] = REQUESTING_PHYSICIANN;
		dictionary_[0x00280010] = ROWS;
		dictionary_[0x00280002] = SAMPLES_PER_PIXEL;
		dictionary_[0x00181316] = SAR;
		dictionary_[0x00180020] = SCANNING_SEQUENCE;
		//SCHEDULED_PROCEDURE_STEP_DESCRIPTION,            
		//SCHEDULED_PROCEDURE_STEP_ID,           
		dictionary_[0x00321021] = SCHEDULED_STUDY_LOCATION_AE_TITLES;
		dictionary_[0x00321000] = SCHEDULED_STUDY_START_DATE;
		dictionary_[0x00321001] = SCHEDULED_STUDY_START_TIME;
		dictionary_[0x00180024] = SEQUENCE_NAME;
		dictionary_[0x00180021] = SEQUENCE_VARIANT;
		dictionary_[0x00080021] = SERIES_DATE;
		dictionary_[0x0008103E] = SERIES_DESCRIPTION;
		dictionary_[0x0020000E] = SERIES_INSTANCE_UID;
		dictionary_[0x00200011] = SERIES_NUMBER;
		dictionary_[0x00080031] = SERIES_TIME;
		dictionary_[0x00201041] = SLICE_LOCATION;
		dictionary_[0x00180050] = SLICE_THICKNESS;
		dictionary_[0x00280106] = SMALLEST_IMAGE_PIXEL_VALUE;
		dictionary_[0x00181020] = SOFTWARE_VERSIONS;
		dictionary_[0x00080016] = SOP_CLASS_UID;
		dictionary_[0x00080018] = SOP_INSTANCE_UID;
		dictionary_[0x00020016] = SOURCE_APPLICATION_ENTITY_TITLE;              
		dictionary_[0x00180088] = SPACING_BETWEEN_SLICES;
		dictionary_[0x00080005] = SPECIFIC_CHARACTER_SET;
		dictionary_[0x00081010] = STATION_NAME;
		dictionary_[0x00324000] = STUDY_COMMENTS;
		dictionary_[0x00080020] = STUDY_DATE;
		dictionary_[0x00081030] = STUDY_DESCRIPTION;
		dictionary_[0x00200010] = STUDY_ID;
		dictionary_[0x0020000D] = STUDY_INSTANCE_UID;
		dictionary_[0x0032000A] = STUDY_STATUS_ID;
		dictionary_[0x00080030] = STUDY_TIME;
		dictionary_[0x00020010] = TRANSFER_SYNTAX_UID;                        
		dictionary_[0x00181251] = TRANSMITTING_COLI;
		dictionary_[0x00181315] = VARIABLE_FLIP_ANGLE_FLAG;
		dictionary_[0x00281050] = WINDOW_CENTER;
		dictionary_[0x00281055] = WINDOW_CENTER_AND_WIDTH_EXPLANATION;
		dictionary_[0x00281051] = WINDOW_WIDTH;
	}
}

/*-----------------------------------------------------------------------------
OTHER
-----------------------------------------------------------------------------*/

Tag_Description TagDictionary::search(int i)
{
	return dictionary_[i];
}