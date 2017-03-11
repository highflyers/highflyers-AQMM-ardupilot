// MESSAGE MEASUREMENT_MESSAGE PACKING

#define MAVLINK_MSG_ID_MEASUREMENT_MESSAGE 195

typedef struct __mavlink_measurement_message_t
{
 char measurement[255]; /*< The measurement*/
} mavlink_measurement_message_t;

#define MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN 255
#define MAVLINK_MSG_ID_180_LEN 255

#define MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_CRC 102
#define MAVLINK_MSG_ID_180_CRC 102

#define MAVLINK_MSG_MEASUREMENT_MESSAGE_FIELD_MEASUREMENT_LEN 255

#define MAVLINK_MESSAGE_INFO_MEASUREMENT_MESSAGE { \
	"MEASUREMENT_MESSAGE", \
	1, \
	{  { "measurement", NULL, MAVLINK_TYPE_CHAR, 255, 0, offsetof(mavlink_measurement_message_t, measurement) }, \
         } \
}


/**
 * @brief Pack a measurement_message message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param measurement The measurement
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_measurement_message_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const char *measurement)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN];

	_mav_put_char_array(buf, 0, measurement, 255);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#else
	mavlink_measurement_message_t packet;

	mav_array_memcpy(packet.measurement, measurement, sizeof(char)*255);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MEASUREMENT_MESSAGE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif
}

/**
 * @brief Pack a measurement_message message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param measurement The measurement
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_measurement_message_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const char *measurement)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN];

	_mav_put_char_array(buf, 0, measurement, 255);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#else
	mavlink_measurement_message_t packet;

	mav_array_memcpy(packet.measurement, measurement, sizeof(char)*255);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MEASUREMENT_MESSAGE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif
}

/**
 * @brief Encode a measurement_message struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param measurement_message C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_measurement_message_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_measurement_message_t* measurement_message)
{
	return mavlink_msg_measurement_message_pack(system_id, component_id, msg, measurement_message->measurement);
}

/**
 * @brief Encode a measurement_message struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param measurement_message C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_measurement_message_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_measurement_message_t* measurement_message)
{
	return mavlink_msg_measurement_message_pack_chan(system_id, component_id, chan, msg, measurement_message->measurement);
}

/**
 * @brief Send a measurement_message message
 * @param chan MAVLink channel to send the message
 *
 * @param measurement The measurement
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_measurement_message_send(mavlink_channel_t chan, const char *measurement)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN];

	_mav_put_char_array(buf, 0, measurement, 255);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE, buf, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE, buf, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif
#else
	mavlink_measurement_message_t packet;

	mav_array_memcpy(packet.measurement, measurement, sizeof(char)*255);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE, (const char *)&packet, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE, (const char *)&packet, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_measurement_message_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *measurement)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_char_array(buf, 0, measurement, 255);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE, buf, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE, buf, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif
#else
	mavlink_measurement_message_t *packet = (mavlink_measurement_message_t *)msgbuf;

	mav_array_memcpy(packet->measurement, measurement, sizeof(char)*255);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE, (const char *)packet, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE, (const char *)packet, MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE MEASUREMENT_MESSAGE UNPACKING


/**
 * @brief Get field measurement from measurement_message message
 *
 * @return The measurement
 */
static inline uint16_t mavlink_msg_measurement_message_get_measurement(const mavlink_message_t* msg, char *measurement)
{
	return _MAV_RETURN_char_array(msg, measurement, 255,  0);
}

/**
 * @brief Decode a measurement_message message into a struct
 *
 * @param msg The message to decode
 * @param measurement_message C-struct to decode the message contents into
 */
static inline void mavlink_msg_measurement_message_decode(const mavlink_message_t* msg, mavlink_measurement_message_t* measurement_message)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_measurement_message_get_measurement(msg, measurement_message->measurement);
#else
	memcpy(measurement_message, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_MEASUREMENT_MESSAGE_LEN);
#endif
}
