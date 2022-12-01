import { useRouter } from "next/router";

// our-domain.com/news/something-important

function DetailPage() {
  const router = useRouter();

  // name of the filename (path in the browser)
  // console.log(router.query.newsId);
  const newsId = router.query.newsId;

  // send a request to the backend API
  // to fecth the news item with newsId

  return <h1>The Detail Page</h1>;
}

export default DetailPage;
