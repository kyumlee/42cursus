import MeetupList from '../components/meetups/MeetupList';

const DUMMY_MEETUPS = [
  {
    id: 'm1',
    title: 'A First Meetup',
    image: 'http://',
    address: 'Some address 5, 12345 Some City',
    description: 'This is a first meetup!'
  },
  {
    id: 'm2',
    title: 'A Second Meetup',
    image: 'http://',
    address: 'Some address 6, 23456 Some City',
    description: 'This is a second meetup!'
  },
];

function HomePage() {
  return <MeetupList meetups={DUMMY_MEETUPS} />
}

export default HomePage;