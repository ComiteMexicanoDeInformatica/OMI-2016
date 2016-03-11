import Prelude
import Data.List
import Control.Monad
import Data.Functor
import System.IO
import Text.Read
import qualified Data.Map as M
import qualified Data.Set as S

data Tipos = 
  N | F | H | A | E | L | O 
  deriving (Read, Ord, Eq, Enum, Show, Bounded)

data Player = 
  Player { ataques :: S.Set Tipos , sp :: Int } 
  deriving (Read, Ord, Eq,Show)

everyElem :: (Enum a, Bounded a) => [a]
everyElem = [minBound .. maxBound]

hReadPlayer :: Handle -> IO Player
hReadPlayer handle = do
  [str,esp] <- fmap words (hGetLine handle)
  let tipos = S.fromList $ map (read . return) str
      points = read esp
  return $ Player tipos points

hReadBaddies :: Handle -> IO Tipos
hReadBaddies handle = do
  str <- hGetLine handle
  return $ read str
  
readEnemies :: IO (Maybe [Int])
readEnemies = do 
  n <- readLn :: IO Int
  tipos <- fmap (sequence . map (readMaybe :: String -> Maybe Int) . words) getLine
  return tipos

goodPlaya :: Player -> S.Set Tipos -> Bool
goodPlaya (Player a _) st = st `S.isSubsetOf` a

esChido :: Int -> [Player] -> M.Map Int Tipos -> [[Int]] ->  Bool
esChido n pys baddies xss = test1 && test2 && test3
  where
    test1 = sort (concat xss) == [1..n]
    test2 = and $ zipWith (\xs (Player _ s) -> s >= (length xs)) xss pys
    test3 = and . zipWith goodPlaya pys . map (S.fromList . map (baddies M.! )) $ xss

main :: IO ()
main = do
  -- read Input
  handle <- openFile "data.in" ReadMode
  [n,k] <- fmap (map (read :: String -> Int) . words) (hGetLine handle)
  pys <- replicateM 4 (fmap (\(Player a s) -> Player a (s `div` k)) (hReadPlayer handle))
  baddies <- fmap (M.fromList . zip [1..]) $ replicateM n (hReadBaddies handle)
  -- read answer
  strategies <- fmap sequence $ replicateM 4 readEnemies
  print $ case fmap (esChido n pys baddies) strategies of
    Just True -> 1
    _         -> 0
  return ()

