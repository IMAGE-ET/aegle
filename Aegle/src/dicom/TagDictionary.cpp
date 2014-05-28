/**
@file TagDictionary.cpp

Created March 10th 2014
*/

#include "TagDictionary.h"

std::map<int, Tag_Description> TagDictionary::tdEnumDictionary_;
std::map<Tag_Description, std::string> TagDictionary::tdNameDictionary_;
std::map<int, Value_Representation> TagDictionary::vrEnumDictionary_;
std::map<Value_Representation, std::string> TagDictionary::vrNameDictionary_;

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

/**
 *	Constructor for the TagDictionary object
 *  
 *  This object is meant to be a static object. There are two static maps which
 *	represent two dictionaries. One to use the tag code to look up the tag 
 *  description and a second to use the tag decription to look up the name in
 *	the form of a string
 *
 * @post If the dictionaries have not been created they will be instantiated
*/
TagDictionary::TagDictionary() 
{
	// check to see if dictionaries has already been created
	if (tdEnumDictionary_.empty())
	{
		createTdEnumDictionary();
	}

	if (tdNameDictionary_.empty())
	{
		createTdNameDictionary();
	}

	if (vrEnumDictionary_.empty())
	{
		createVrEnumDictionary();
	}

	if (vrNameDictionary_.empty())
	{
		createVrNameDictionary();
	}
}

/*-----------------------------------------------------------------------------
OTHER PUBLIC
-----------------------------------------------------------------------------*/

Tag_Description TagDictionary::searchDescription(int value)
{
	return tdEnumDictionary_[value];
}

Value_Representation TagDictionary::searchVr(int value)
{
	return vrEnumDictionary_[value];
}

std::string TagDictionary::toString(Tag_Description tagDescription)
{
	return tdNameDictionary_[tagDescription];
}

std::string TagDictionary::toString(Value_Representation vr)
{
	return vrNameDictionary_[vr];
}

std::string TagDictionary::toTagName(int value)
{
	Tag_Description td;

	td = searchDescription(value);

	return tdNameDictionary_[td];
}

std::string TagDictionary::toVrName(int value)
{
	Value_Representation vr;

	vr = searchVr(value);

	return vrNameDictionary_[vr];
}

/*-----------------------------------------------------------------------------
OTHER PRIVATE
-----------------------------------------------------------------------------*/

void TagDictionary::createTdEnumDictionary()
{
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080050, ACCESSION_NUMBER));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080022, ACQUISITION_DATE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181310, ACQUISITION_MATRIX));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00200012, ACQUISITION_NUMBER));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080032, ACQUISITION_TIME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180025, ANGIO_FLAG));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280100, BITS_ALLOCATED));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280101, BITS_STORED));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280011, COLUMNS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181318, DB_DT));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181000, DEVICE_SERIAL_NUMBER));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180086, ECHO_NUMBERS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180081, ECHO_TIME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180091, ECHO_TRAIN_LENGTH));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00020001, FILE_META_INFORMATION_VERSION));               
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181314, FLIP_ANGLE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00200052, FRAME_OF_REFERENCE_UID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00020000, GROUP_LENGTH));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280102, HIGH_BIT));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00204000, IMAGE_COMMENTS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080023, IMAGE_DATE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00200013, IMAGE_NUMBER));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00200037, IMAGE_ORIENTATION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00200032, IMAGE_POSITION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080033, IMAGE_TIME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080008, IMAGE_TYPE));                                  
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180085, IMAGED_NUCLEUS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180084, IMAGING_FREQUENCY));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00020012, IMPLEMENTATION_CLASS_UID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00020013, IMPLEMENTATION_VERSION_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080080, INSTITUTION_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0xFFFEE000, ITEM));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280107, LARGEST_IMAGE_PIXEL_VALUE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00282110, LOSSY_IMAGE_COMPRESSION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00282112, LOSSY_IMAGE_COMPRESSION_RATIO));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180087, MAGNETIC_FIELD_STRENGTH));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080070, MANUFACTURER));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081090, MANUFACTURERS_MODEL_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00020002, MEDIA_STORAGE_SOP_CLASS_UID));                     
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00020003, MEDIA_STORAGE_SOP_INSTANCE_UID));                 
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080060, MODALITY));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180023, MR_ACQUISITION_TYPE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180083, NUMBER_OF_AVERAGES));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180089, NUMBER_OF_PHASE_ENCODING_STEPS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081070, OPERATORS_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00100020, PATIENT_ID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00185100, PATIENT_POSITION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00101010, PATIENTS_AGE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00100010, PATIENTS_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00101030, PATIENTS_WEIGHT));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180094, PERCENT_PHASE_FIELD_OF_VIEW));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180093, PERCENT_SAMPLING));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00400275, PERFORMED_PROCEDURE_STEP_DESCRIPTION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00400244, PERFORMED_PROCEDURE_STEP_START_DATE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00400245, PERFORMED_PROCEDURE_STEP_START_TIME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181312, PHASE_ENCODING_DIRECTION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280004, PHOTOMETRIC_INTERPRETATION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180095, PIXEL_BANDWIDTH));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280103, PIXEL_REPRESENTATION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280030, PIXEL_SPACING));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181030, PROTOCOL_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081140, REFERENCED_IMAGE_SEQUENCE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081120, REFERENCED_PATIENT_SEQUENCE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081150, REFERENCED_SOP_CLASS_UID));                    
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081155, REFERENCED_SOP_INSTANCE_UID));                    
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081111, REFERENCED_STUDY_COMPONENT_SEQUENCE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081110, REFERENCED_STUDY_SEQUENCE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080090, REFERRING_PHYSICIANS_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180080, REPETITION_TIME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00400275, REQUEST_ATTRIBUTES_SEQUENCE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00321060, REQUESTED_PROCEDURE_DESCRIPTION));
	//REQUESTED_PROCEDURE_ID,                
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00321032, REQUESTING_PHYSICIANN));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280010, ROWS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280002, SAMPLES_PER_PIXEL));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181316, SAR));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180020, SCANNING_SEQUENCE));
	//SCHEDULED_PROCEDURE_STEP_DESCRIPTION,            
	//SCHEDULED_PROCEDURE_STEP_ID,           
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00321021, SCHEDULED_STUDY_LOCATION_AE_TITLES));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00321000, SCHEDULED_STUDY_START_DATE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00321001, SCHEDULED_STUDY_START_TIME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180024, SEQUENCE_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180021, SEQUENCE_VARIANT));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080021, SERIES_DATE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x0008103E, SERIES_DESCRIPTION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x0020000E, SERIES_INSTANCE_UID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00200011, SERIES_NUMBER));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080031, SERIES_TIME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00201041, SLICE_LOCATION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180050, SLICE_THICKNESS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00280106, SMALLEST_IMAGE_PIXEL_VALUE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181020, SOFTWARE_VERSIONS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080016, SOP_CLASS_UID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080018, SOP_INSTANCE_UID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00020016, SOURCE_APPLICATION_ENTITY_TITLE));              
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00180088, SPACING_BETWEEN_SLICES));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080005, SPECIFIC_CHARACTER_SET));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081010, STATION_NAME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00324000, STUDY_COMMENTS));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080020, STUDY_DATE));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00081030, STUDY_DESCRIPTION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00200010, STUDY_ID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x0020000D, STUDY_INSTANCE_UID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x0032000A, STUDY_STATUS_ID));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00080030, STUDY_TIME));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00020010, TRANSFER_SYNTAX_UID));                        
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181251, TRANSMITTING_COLI));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00181315, VARIABLE_FLIP_ANGLE_FLAG));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00281050, WINDOW_CENTER));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00281055, WINDOW_CENTER_AND_WIDTH_EXPLANATION));
	tdEnumDictionary_.insert(std::pair<int, Tag_Description>(0x00281051, WINDOW_WIDTH));
}

void TagDictionary::createTdNameDictionary()
{
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ACCESSION_NUMBER, "ACCESSION_NUMBER"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ACQUISITION_DATE, "ACQUISITION_DATE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ACQUISITION_MATRIX, "ACQUISITION_MATRIX"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ACQUISITION_NUMBER, "ACQUISITION_NUMBER"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ACQUISITION_TIME, "ACQUISITION_TIME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ANGIO_FLAG, "ANGIO_FLAG"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(BITS_ALLOCATED, "BITS_ALLOCATED"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(BITS_STORED, "BITS_STORED"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(COLUMNS, "COLUMNS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(DB_DT, "DB_DT"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(DEVICE_SERIAL_NUMBER, "DEVICE_SERIAL_NUMBER"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ECHO_NUMBERS, "ECHO_NUMBERS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ECHO_TIME, "ECHO_TIME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ECHO_TRAIN_LENGTH, "ECHO_TRAIN_LENGTH"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(FILE_META_INFORMATION_VERSION, "FILE_META_INFORMATION_VERSION"));               
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(FLIP_ANGLE, "FLIP_ANGLE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(FRAME_OF_REFERENCE_UID, "FRAME_OF_REFERENCE_UID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(GROUP_LENGTH, "GROUP_LENGTH"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(HIGH_BIT, "HIGH_BIT"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_COMMENTS, "IMAGE_COMMENTS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_DATE, "IMAGE_DATE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_NUMBER, "IMAGE_NUMBER"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_ORIENTATION, "IMAGE_ORIENTATION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_POSITION, "IMAGE_POSITION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_TIME, "IMAGE_TIME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_TYPE, "IMAGE_TYPE"));                                  
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGED_NUCLEUS, "IMAGED_NUCLEUS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGING_FREQUENCY, "IMAGING_FREQUENCY"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMPLEMENTATION_CLASS_UID, "IMPLEMENTATION_CLASS_UID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(IMPLEMENTATION_VERSION_NAME, "IMPLEMENTATION_VERSION_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(INSTITUTION_NAME, "INSTITUTION_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ITEM, "ITEM"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(LARGEST_IMAGE_PIXEL_VALUE, "LARGEST_IMAGE_PIXEL_VALUE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(LOSSY_IMAGE_COMPRESSION, "LOSSY_IMAGE_COMPRESSION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(LOSSY_IMAGE_COMPRESSION_RATIO, "LOSSY_IMAGE_COMPRESSION_RATIO"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(MAGNETIC_FIELD_STRENGTH, "MAGNETIC_FIELD_STRENGTH"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(MANUFACTURER, "MANUFACTURER"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(MANUFACTURERS_MODEL_NAME, "MANUFACTURERS_MODEL_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(MEDIA_STORAGE_SOP_CLASS_UID, "MEDIA_STORAGE_SOP_CLASS_UID"));                     
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(MEDIA_STORAGE_SOP_INSTANCE_UID, "MEDIA_STORAGE_SOP_INSTANCE_UID"));                 
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(MODALITY, "MODALITY"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(MR_ACQUISITION_TYPE, "MR_ACQUISITION_TYPE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(NUMBER_OF_AVERAGES, "NUMBER_OF_AVERAGES"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(NUMBER_OF_PHASE_ENCODING_STEPS, "NUMBER_OF_PHASE_ENCODING_STEPS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(OPERATORS_NAME, "OPERATORS_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENT_ID, "PATIENT_ID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENT_POSITION, "PATIENT_POSITION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENTS_AGE, "PATIENTS_AGE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENTS_NAME, "PATIENTS_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENTS_WEIGHT, "PATIENTS_WEIGHT"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PERCENT_PHASE_FIELD_OF_VIEW, "PERCENT_PHASE_FIELD_OF_VIEW"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PERCENT_SAMPLING, "PERCENT_SAMPLING"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PERFORMED_PROCEDURE_STEP_DESCRIPTION, "PERFORMED_PROCEDURE_STEP_DESCRIPTION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PERFORMED_PROCEDURE_STEP_START_DATE, "PERFORMED_PROCEDURE_STEP_START_DATE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PERFORMED_PROCEDURE_STEP_START_TIME, "PERFORMED_PROCEDURE_STEP_START_TIME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PHASE_ENCODING_DIRECTION, "PHASE_ENCODING_DIRECTION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PHOTOMETRIC_INTERPRETATION, "PHOTOMETRIC_INTERPRETATION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PIXEL_BANDWIDTH, "PIXEL_BANDWIDTH"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PIXEL_REPRESENTATION, "PIXEL_REPRESENTATION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PIXEL_SPACING, "PIXEL_SPACING"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(PROTOCOL_NAME, "PROTOCOL_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_IMAGE_SEQUENCE, "REFERENCED_IMAGE_SEQUENCE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_PATIENT_SEQUENCE, "REFERENCED_PATIENT_SEQUENCE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_SOP_CLASS_UID, "REFERENCED_SOP_CLASS_UID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_SOP_INSTANCE_UID, "REFERENCED_SOP_INSTANCE_UID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_STUDY_COMPONENT_SEQUENCE, "REFERENCED_STUDY_COMPONENT_SEQUENCE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_STUDY_SEQUENCE, "REFERENCED_STUDY_SEQUENCE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERRING_PHYSICIANS_NAME, "REFERRING_PHYSICIANS_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REPETITION_TIME, "REPETITION_TIME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REQUEST_ATTRIBUTES_SEQUENCE, "REQUEST_ATTRIBUTES_SEQUENCE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REQUESTED_PROCEDURE_DESCRIPTION, "REQUESTED_PROCEDURE_DESCRIPTION"));
	//REQUESTED_PROCEDURE_ID,                
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(REQUESTING_PHYSICIANN, "REQUESTING_PHYSICIANN"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(ROWS, "ROWS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SAMPLES_PER_PIXEL, "SAMPLES_PER_PIXEL"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SAR, "SAR"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SCANNING_SEQUENCE, "SCANNING_SEQUENCE"));
	//SCHEDULED_PROCEDURE_STEP_DESCRIPTION,            
	//SCHEDULED_PROCEDURE_STEP_ID,           
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SCHEDULED_STUDY_LOCATION_AE_TITLES, "SCHEDULED_STUDY_LOCATION_AE_TITLES"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SCHEDULED_STUDY_START_DATE, "SCHEDULED_STUDY_START_DATE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SCHEDULED_STUDY_START_TIME, "SCHEDULED_STUDY_START_TIME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SEQUENCE_NAME, "SEQUENCE_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SEQUENCE_VARIANT, "SEQUENCE_VARIANT"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_DATE, "SERIES_DATE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_DESCRIPTION, "SERIES_DESCRIPTION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_INSTANCE_UID, "SERIES_INSTANCE_UID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_NUMBER, "SERIES_NUMBER"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_TIME, "SERIES_TIME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SLICE_LOCATION, "SLICE_LOCATION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SLICE_THICKNESS, "SLICE_THICKNESS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SMALLEST_IMAGE_PIXEL_VALUE, "SMALLEST_IMAGE_PIXEL_VALUE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SOFTWARE_VERSIONS, "SOFTWARE_VERSIONS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SOP_CLASS_UID, "SOP_CLASS_UID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SOP_INSTANCE_UID, "SOP_INSTANCE_UID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SOURCE_APPLICATION_ENTITY_TITLE, "SOURCE_APPLICATION_ENTITY_TITLE"));              
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SPACING_BETWEEN_SLICES, "SPACING_BETWEEN_SLICES"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(SPECIFIC_CHARACTER_SET, "SPECIFIC_CHARACTER_SET"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(STATION_NAME, "STATION_NAME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_COMMENTS, "STUDY_COMMENTS"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_DATE, "STUDY_DATE"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_DESCRIPTION, "STUDY_DESCRIPTION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_ID, "STUDY_ID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_INSTANCE_UID, "STUDY_INSTANCE_UID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_STATUS_ID, "STUDY_STATUS_ID"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_TIME, "STUDY_TIME"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(TRANSFER_SYNTAX_UID, "TRANSFER_SYNTAX_UID"));                        
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(TRANSMITTING_COLI, "TRANSMITTING_COLI"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(VARIABLE_FLIP_ANGLE_FLAG, "VARIABLE_FLIP_ANGLE_FLAG"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(WINDOW_CENTER, "WINDOW_CENTER"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(WINDOW_CENTER_AND_WIDTH_EXPLANATION, "WINDOW_CENTER_AND_WIDTH_EXPLANATION"));
	tdNameDictionary_.insert(std::pair<Tag_Description, std::string>(WINDOW_WIDTH, "WINDOW_WIDTH"));
}

void TagDictionary::createVrEnumDictionary()
{
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x0000554E, UN));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004145, AE));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004153, AS));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004154, AT));                        
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004353, CS));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004441, DA));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004453, DS));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004454, DT));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x0000464C, FL));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004644, FD));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004953, IS));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004C4F, LO));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004C54, LT));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004F42, OB));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004F46, OF));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00004F57, OW));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x0000504E, PN));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00005348, SH));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x0000534C, SL));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00005351, SQ));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00005353, SS));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00005354, ST));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x0000544D, TM));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00005549, UI));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x0000554C, UL));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00005553, US));
	vrEnumDictionary_.insert(std::pair<int, Value_Representation>(0x00005554, UT));
}

void TagDictionary::createVrNameDictionary()
{
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(UN, "Unknown"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(AE, "Application Entity"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(AS, "Age String")); 
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(AT, "Attribute Tag"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(CS, "Code String"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(DA, "Date"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(DS, "Decimal String"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(DT, "Date Time "));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(FL, "Single Precision Floating Point"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(FD, "Double Precision Floating Point"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(IS, "Integer"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(LO, "Character String"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(LT, "Long Text"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(OB, "Other Byte String"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(OF, "Other Float String"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(OW, "Other Word String"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(PN, "Person's Name"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(SH, "Short String"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(SL, "Signed Long Integer"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(SQ, "Sequence of Zero or More"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(SS, "Signed Short Integer"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(ST, "Short Text"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(TM, "Time"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(UI, "Uniqe Identifier"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(UL, "Unsigned Long Integer"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(US, "Unsigned Short Integer"));
	vrNameDictionary_.insert(std::pair<Value_Representation, std::string>(UT,  "Unlimited Text"));
}