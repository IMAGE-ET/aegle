/**
@file TagDictionary.cpp

Created March 10th 2014
*/

#include "TagDictionary.h"

std::map<int, Tag_Description> TagDictionary::enumDictionary_;
std::map<Tag_Description, std::string> TagDictionary::nameDictionary_;

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
	if (enumDictionary_.size())
	{
		// create dictionary
		createEnumDictionary();
	}

	// check to see if dictionaries has already been created
	if (nameDictionary_.size())
	{
		// create dictionary
		createNameDictionary();
	}
}

/*-----------------------------------------------------------------------------
OTHER PUBLIC
-----------------------------------------------------------------------------*/

Tag_Description TagDictionary::searchDescription(int value)
{
	return enumDictionary_[value];
}

std::string TagDictionary::toString(Tag_Description tagDescription)
{
	return nameDictionary_[tagDescription];
}

std::string TagDictionary::toString(int value)
{
	Tag_Description td;

	td = searchDescription(value);
	
	return nameDictionary_[td];
}

/*-----------------------------------------------------------------------------
OTHER PRIVATE
-----------------------------------------------------------------------------*/

void TagDictionary::createEnumDictionary()
{
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080050, ACCESSION_NUMBER));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080022, ACQUISITION_DATE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181310, ACQUISITION_MATRIX));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00200012, ACQUISITION_NUMBER));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080032, ACQUISITION_TIME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180025, ANGIO_FLAG));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280100, BITS_ALLOCATED));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280101, BITS_STORED));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280011, COLUMNS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181318, DB_DT));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181000, DEVICE_SERIAL_NUMBER));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180086, ECHO_NUMBERS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180081, ECHO_TIME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180091, ECHO_TRAIN_LENGTH));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00020001, FILE_META_INFORMATION_VERSION));               
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181314, FLIP_ANGLE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00200052, FRAME_OF_REFERENCE_UID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00020000, GROUP_LENGTH));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280102, HIGH_BIT));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00204000, IMAGE_COMMENTS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080023, IMAGE_DATE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00200013, IMAGE_NUMBER));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00200037, IMAGE_ORIENTATION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00200032, IMAGE_POSITION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080033, IMAGE_TIME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080008, IMAGE_TYPE));                                  
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180085, IMAGED_NUCLEUS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180084, IMAGING_FREQUENCY));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00020012, IMPLEMENTATION_CLASS_UID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00020013, IMPLEMENTATION_VERSION_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080080, INSTITUTION_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280107, LARGEST_IMAGE_PIXEL_VALUE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00282110, LOSSY_IMAGE_COMPRESSION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00282112, LOSSY_IMAGE_COMPRESSION_RATIO));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180087, MAGNETIC_FIELD_STRENGTH));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080070, MANUFACTURER));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00081090, MANUFACTURERS_MODEL_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00020002, MEDIA_STORAGE_SOP_CLASS_UID));                     
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00020003, MEDIA_STORAGE_SOP_INSTANCE_UID));                 
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080060, MODALITY));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180023, MR_ACQUISITION_TYPE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180083, NUMBER_OF_AVERAGES));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180089, NUMBER_OF_PHASE_ENCODING_STEPS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00081070, OPERATORS_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00100020, PATIENT_ID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00185100, PATIENT_POSITION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00101010, PATIENTS_AGE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00100010, PATIENTS_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00101030, PATIENTS_WEIGHT));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180094, PERCENT_PHASE_FIELD_OF_VIEW));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180093, PERCENT_SAMPLING));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00400275, PERFORMED_PROCEDURE_STEP_DESCRIPTION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00400244, PERFORMED_PROCEDURE_STEP_START_DATE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00400245, PERFORMED_PROCEDURE_STEP_START_TIME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181312, PHASE_ENCODING_DIRECTION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280004, PHOTOMETRIC_INTERPRETATION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180095, PIXEL_BANDWIDTH));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280103, PIXEL_REPRESENTATION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280030, PIXEL_SPACING));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181030, PROTOCOL_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00081140, REFERENCED_IMAGE_SEQUENCE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00081120, REFERENCED_PATIENT_SEQUENCE));
	//REFERENCED_SOP_CLASS_UID,                     
	//REFERENCED_SOP_INSTANCE_UID,                    
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00081111, REFERENCED_STUDY_COMPONENT_SEQUENCE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00081110, REFERENCED_STUDY_SEQUENCE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080090, REFERRING_PHYSICIANS_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180080, REPETITION_TIME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00400275, REQUEST_ATTRIBUTES_SEQUENCE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00321060, REQUESTED_PROCEDURE_DESCRIPTION));
	//REQUESTED_PROCEDURE_ID,                
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00321032, REQUESTING_PHYSICIANN));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280010, ROWS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280002, SAMPLES_PER_PIXEL));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181316, SAR));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180020, SCANNING_SEQUENCE));
	//SCHEDULED_PROCEDURE_STEP_DESCRIPTION,            
	//SCHEDULED_PROCEDURE_STEP_ID,           
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00321021, SCHEDULED_STUDY_LOCATION_AE_TITLES));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00321000, SCHEDULED_STUDY_START_DATE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00321001, SCHEDULED_STUDY_START_TIME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180024, SEQUENCE_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180021, SEQUENCE_VARIANT));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080021, SERIES_DATE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x0008103E, SERIES_DESCRIPTION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x0020000E, SERIES_INSTANCE_UID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00200011, SERIES_NUMBER));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080031, SERIES_TIME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00201041, SLICE_LOCATION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180050, SLICE_THICKNESS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00280106, SMALLEST_IMAGE_PIXEL_VALUE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181020, SOFTWARE_VERSIONS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080016, SOP_CLASS_UID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080018, SOP_INSTANCE_UID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00020016, SOURCE_APPLICATION_ENTITY_TITLE));              
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00180088, SPACING_BETWEEN_SLICES));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080005, SPECIFIC_CHARACTER_SET));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00081010, STATION_NAME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00324000, STUDY_COMMENTS));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080020, STUDY_DATE));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00081030, STUDY_DESCRIPTION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00200010, STUDY_ID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x0020000D, STUDY_INSTANCE_UID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x0032000A, STUDY_STATUS_ID));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00080030, STUDY_TIME));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00020010, TRANSFER_SYNTAX_UID));                        
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181251, TRANSMITTING_COLI));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00181315, VARIABLE_FLIP_ANGLE_FLAG));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00281050, WINDOW_CENTER));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00281055, WINDOW_CENTER_AND_WIDTH_EXPLANATION));
	enumDictionary_.insert(std::pair<int, Tag_Description>(0x00281051, WINDOW_WIDTH));
}

void TagDictionary::createNameDictionary()
{
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ACCESSION_NUMBER, "ACCESSION_NUMBER"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ACCESSION_NUMBER, "ACCESSION_NUMBER"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ACQUISITION_MATRIX, "ACQUISITION_MATRIX"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ACQUISITION_NUMBER, "ACQUISITION_NUMBER"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ACQUISITION_TIME, "ACQUISITION_TIME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ANGIO_FLAG, "ANGIO_FLAG"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(BITS_ALLOCATED, "BITS_ALLOCATED"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(BITS_STORED, "BITS_STORED"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(COLUMNS, "COLUMNS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(DB_DT, "DB_DT"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(DEVICE_SERIAL_NUMBER, "DEVICE_SERIAL_NUMBER"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ECHO_NUMBERS, "ECHO_NUMBERS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ECHO_TIME, "ECHO_TIME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ECHO_TRAIN_LENGTH, "ECHO_TRAIN_LENGTH"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(FILE_META_INFORMATION_VERSION, "FILE_META_INFORMATION_VERSION"));               
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(FLIP_ANGLE, "FLIP_ANGLE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(FRAME_OF_REFERENCE_UID, "FRAME_OF_REFERENCE_UID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(GROUP_LENGTH, "GROUP_LENGTH"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(HIGH_BIT, "HIGH_BIT"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_COMMENTS, "IMAGE_COMMENTS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_DATE, "IMAGE_DATE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_NUMBER, "IMAGE_NUMBER"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_ORIENTATION, "IMAGE_ORIENTATION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_POSITION, "IMAGE_POSITION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_TIME, "IMAGE_TIME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGE_TYPE, "IMAGE_TYPE"));                                  
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGED_NUCLEUS, "IMAGED_NUCLEUS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMAGING_FREQUENCY, "IMAGING_FREQUENCY"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMPLEMENTATION_CLASS_UID, "IMPLEMENTATION_CLASS_UID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(IMPLEMENTATION_VERSION_NAME, "IMPLEMENTATION_VERSION_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(INSTITUTION_NAME, "INSTITUTION_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(LARGEST_IMAGE_PIXEL_VALUE, "LARGEST_IMAGE_PIXEL_VALUE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(LOSSY_IMAGE_COMPRESSION, "LOSSY_IMAGE_COMPRESSION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(LOSSY_IMAGE_COMPRESSION_RATIO, "LOSSY_IMAGE_COMPRESSION_RATIO"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(MAGNETIC_FIELD_STRENGTH, "MAGNETIC_FIELD_STRENGTH"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(MANUFACTURER, "MANUFACTURER"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(MANUFACTURERS_MODEL_NAME, "MANUFACTURERS_MODEL_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(MEDIA_STORAGE_SOP_CLASS_UID, "MEDIA_STORAGE_SOP_CLASS_UID"));                     
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(MEDIA_STORAGE_SOP_INSTANCE_UID, "MEDIA_STORAGE_SOP_INSTANCE_UID"));                 
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(MODALITY, "MODALITY"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(MR_ACQUISITION_TYPE, "MR_ACQUISITION_TYPE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(NUMBER_OF_AVERAGES, "NUMBER_OF_AVERAGES"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(NUMBER_OF_PHASE_ENCODING_STEPS, "NUMBER_OF_PHASE_ENCODING_STEPS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(OPERATORS_NAME, "OPERATORS_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENT_ID, "PATIENT_ID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENT_POSITION, "PATIENT_POSITION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENTS_AGE, "PATIENTS_AGE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENTS_NAME, "PATIENTS_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PATIENTS_WEIGHT, "PATIENTS_WEIGHT"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PERCENT_PHASE_FIELD_OF_VIEW, "PERCENT_PHASE_FIELD_OF_VIEW"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PERCENT_SAMPLING, "PERCENT_SAMPLING"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PERFORMED_PROCEDURE_STEP_DESCRIPTION, "PERFORMED_PROCEDURE_STEP_DESCRIPTION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PERFORMED_PROCEDURE_STEP_START_DATE, "PERFORMED_PROCEDURE_STEP_START_DATE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PERFORMED_PROCEDURE_STEP_START_TIME, "PERFORMED_PROCEDURE_STEP_START_TIME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PHASE_ENCODING_DIRECTION, "PHASE_ENCODING_DIRECTION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PHOTOMETRIC_INTERPRETATION, "PHOTOMETRIC_INTERPRETATION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PIXEL_BANDWIDTH, "PIXEL_BANDWIDTH"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PIXEL_REPRESENTATION, "PIXEL_REPRESENTATION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PIXEL_SPACING, "PIXEL_SPACING"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(PROTOCOL_NAME, "PROTOCOL_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_IMAGE_SEQUENCE, "REFERENCED_IMAGE_SEQUENCE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_PATIENT_SEQUENCE, "REFERENCED_PATIENT_SEQUENCE"));
	//REFERENCED_SOP_CLASS_UID,                     
	//REFERENCED_SOP_INSTANCE_UID,                    
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_STUDY_COMPONENT_SEQUENCE, "REFERENCED_STUDY_COMPONENT_SEQUENCE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERENCED_STUDY_SEQUENCE, "REFERENCED_STUDY_SEQUENCE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REFERRING_PHYSICIANS_NAME, "REFERRING_PHYSICIANS_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REPETITION_TIME, "REPETITION_TIME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REQUEST_ATTRIBUTES_SEQUENCE, "REQUEST_ATTRIBUTES_SEQUENCE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REQUESTED_PROCEDURE_DESCRIPTION, "REQUESTED_PROCEDURE_DESCRIPTION"));
	//REQUESTED_PROCEDURE_ID,                
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(REQUESTING_PHYSICIANN, "REQUESTING_PHYSICIANN"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(ROWS, "ROWS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SAMPLES_PER_PIXEL, "SAMPLES_PER_PIXEL"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SAR, "SAR"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SCANNING_SEQUENCE, "SCANNING_SEQUENCE"));
	//SCHEDULED_PROCEDURE_STEP_DESCRIPTION,            
	//SCHEDULED_PROCEDURE_STEP_ID,           
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SCHEDULED_STUDY_LOCATION_AE_TITLES, "SCHEDULED_STUDY_LOCATION_AE_TITLES"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SCHEDULED_STUDY_START_DATE, "SCHEDULED_STUDY_START_DATE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SCHEDULED_STUDY_START_TIME, "SCHEDULED_STUDY_START_TIME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SEQUENCE_NAME, "SEQUENCE_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SEQUENCE_VARIANT, "SEQUENCE_VARIANT"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_DATE, "SERIES_DATE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_DESCRIPTION, "SERIES_DESCRIPTION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_INSTANCE_UID, "SERIES_INSTANCE_UID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_NUMBER, "SERIES_NUMBER"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SERIES_TIME, "SERIES_TIME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SLICE_LOCATION, "SLICE_LOCATION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SLICE_THICKNESS, "SLICE_THICKNESS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SMALLEST_IMAGE_PIXEL_VALUE, "SMALLEST_IMAGE_PIXEL_VALUE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SOFTWARE_VERSIONS, "SOFTWARE_VERSIONS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SOP_CLASS_UID, "SOP_CLASS_UID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SOP_INSTANCE_UID, "SOP_INSTANCE_UID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SOURCE_APPLICATION_ENTITY_TITLE, "SOURCE_APPLICATION_ENTITY_TITLE"));              
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SPACING_BETWEEN_SLICES, "SPACING_BETWEEN_SLICES"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(SPECIFIC_CHARACTER_SET, "SPECIFIC_CHARACTER_SET"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(STATION_NAME, "STATION_NAME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_COMMENTS, "STUDY_COMMENTS"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_DATE, "STUDY_DATE"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_DESCRIPTION, "STUDY_DESCRIPTION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_ID, "STUDY_ID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_INSTANCE_UID, "STUDY_INSTANCE_UID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_STATUS_ID, "STUDY_STATUS_ID"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(STUDY_TIME, "STUDY_TIME"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(TRANSFER_SYNTAX_UID, "TRANSFER_SYNTAX_UID"));                        
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(TRANSMITTING_COLI, "TRANSMITTING_COLI"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(VARIABLE_FLIP_ANGLE_FLAG, "VARIABLE_FLIP_ANGLE_FLAG"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(WINDOW_CENTER, "WINDOW_CENTER"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(WINDOW_CENTER_AND_WIDTH_EXPLANATION, "WINDOW_CENTER_AND_WIDTH_EXPLANATION"));
	nameDictionary_.insert(std::pair<Tag_Description, std::string>(WINDOW_WIDTH, "WINDOW_WIDTH"));
}